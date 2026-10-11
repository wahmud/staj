#include <stdio.h>
#include <string.h>
struct Kategoriler {
    char kategori[21];
    struct Kategoriler* sonraki;
};
struct Harcamalar {
    char harcama[38];
    struct Harcamalar* sonraki;
};
int main(int argc, char* argv[])
{
    struct Kategoriler* dugum_kat;
    struct Harcamalar* dugum_har;
    //DOSYADAN OKUYUP HARCAMA BAĞLI LİSTESİNİ DOLDUR
    //DOSYADAN OKUYUP KATEGORİ BAĞLI LİSTESİNİ DOLDUR
    //AMA BUNU BAŞARILI KOMUT GİRİŞİMİNDEN SONRA YAP (HER BİR KOMUTTA)

    if (argc < 3 || argc > 5 || argc == 4) {
        printf("komut taninmadi1\n");
    }

    else if (argc == 5) {
        if (!strcmp(argv[1], "ekle")){
            printf("ekleme komutuna gelindi\n");
            int gun, ay, yil;
            int sscanf_ret_1 = sscanf(argv[2], "%d-%d-%d", &gun, &ay, &yil);
            if (sscanf_ret_1 == 3) {
                if (is_real_time(argv[2])) {
                    if(!liste_ara(dugum_kat, argv[3])) {
                        if (!kat_gecerli_mi(argv[3])) {
                            printf("Girilen Kategori Gecersiz. Yeniden Deneyin");
                            //return 1;
                        }
                    }
                    double temp_tutar = 0.;
                    int sscanf_ret2 = sscanf(argv[4], "%f", &temp_tutar);
                    if (sscanf_ret2 != 1) {
                        printf("Sayi Girilmedi");
                        //return 1;
                    }
                    else if (temp_tutar != (int)temp_tutar) {
                            printf("Tutar Girisi Tam Sayi Olmali\n");
                            //return 1;
                    }
                    else if (temp_tutar != 0) {
                        //dosyadan oku: harcama düğümlerini doldur.
                        int kayitlari_oku_ret = kayitlari_oku(&dugum_har);
                        if (kayitlari_oku_ret == -1) {
                            printf("Bellek Alani Eklenemedi. Program Sonlandirildi\n");
                            liste_bosalt(&dugum_har);
                            return 1;
                        }
                        //bitti


                        //yeni harcamayı ekle
                        struct Harcamalar* temp_harcama;
                        strcat(temp_harcama->harcama, argv[2]);
                        strcat(temp_harcama->harcama, argv[3]);
                        strcat(temp_harcama->harcama, argv[4]);
                        
                        struct Dugum* dugum_ekle_ret = dugum_ekle(&dugum_har, temp_harcama->harcama);
                        if (!dugum_ekle_ret) {
                            printf("Bellek alani eklenemedi, program sonlandirildi\n");
                            liste_bosalt(&dugum_har);
                            return 1;
                        }

                        //bitti


                        //sırala
                        liste_sirala(&dugum_har);
                        //bitti


                        //dosyaya yaz
                        int yazma_ret = kayitlari_yaz(dugum_har);
                        if (yazma_ret == 1) {
                            printf("Dosya acilamadi, program sonlandirildi\n");
                            liste_bosalt(&dugum_har);
                            return 1;
                        }
                        //bitti


                        //boşalt ve çık
                        liste_bosalt(&dugum_har);
                        return 0;
                        //bitti
                    }
                    else {
                        printf("Tutar Olarak Sifir Degeri Girilemez");
                        //return 1;
                    }
                }
                else {
                    printf("Takvimde Mevcut Olmayan Bir Tarih Girildi\n");
                    //return 1;
                }
            }
            else {
                printf("Hatali Tarih Girisi\n");
                //return 1;
            }
        }
        else {
            printf("komut taninmadi2\n");
            //return 1;
        }
    }






    
    else if (argc == 3) {
        if (!strcmp(argv[1], "liste")) {
            printf("listeleme komutuna gelindi\n");
            //sonraki yazıları kontrol et
                //argv[2] geçerli bir ay-tarihi olmalı
        }
        else if (!strcmp(argv[1], "ozet")) {
            printf("ozetleme komutuna gelindi\n");
            //sonraki yazıları kontrol et
                //argv[2] geçerli bir ay-tarihi olmalı
        }
        else {
            printf("komut taninmadi3\n");
            //return 1;
        }
    }

}