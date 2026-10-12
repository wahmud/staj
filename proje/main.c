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
            if (gecerli_gun_tarihi_mi(argv[2])) {
                if (!kat_gecerli_mi(argv[3])) {
                    printf("Girilen Kategori Gecersiz. Yeniden Deneyin");
                    return 1;
                }
                double temp_tutar = 0.;
                int sscanf_ret2 = sscanf(argv[4], "%f", &temp_tutar);
                if (sscanf_ret2 != 1) {
                    printf("Sayi Girilmedi");
                    return 1;
                }
                else if (temp_tutar != (int)temp_tutar) {
                        printf("Tutar Girisi Tam Sayi Olmali\n");
                        return 1;
                }
                else if (temp_tutar != 0) {
                    //dosyadan oku
                    int kayitlari_oku_ret = kayitlari_oku(&dugum_har);
                    if (kayitlari_oku_ret == -1) {
                        printf("Bellek Alani Eklenemedi\n");
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
                        printf("Bellek alani eklenemedi\n");
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
                        printf("Dosya acilamadi\n");
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
                    return 1;
                }
            }
            else {
                printf("Hatali Tarih Girisi\n");
                return 1;
            }
        }
        else {
            printf("komut taninmadi2\n");
            return 1;
        }
    }






    
    else if (argc == 3) {
        if (!strcmp(argv[1], "liste")) {
            printf("listeleme komutuna gelindi\n");
            if (gecerli_ay_tarihi_mi(argv[1])) {
                int okuyup_basma_ret = dosyadan_ay_tarihini_baz_alip_anbean_okuyup_basmak_icin_fonksiyon_adi(argv[1]);
                if (!okuyup_basma_ret) {
                    printf("Dosya Acilamadi\n");
                    return 1;
                }
            }
            else {
                printf("Gecerli Bir Ay Tarihi Girilmedi");
                return 1;
            }
        }




        else if (!strcmp(argv[1], "ozet")) {
            printf("ozetleme komutuna gelindi\n");
            if (gecerli_ay_tarihi_mi(argv[1])) {
                //dosyadan oku
                //harcamalar ve kategori düğümleri doldur

                //düğümleri müğümleri doldurma
                //git şunu yap, fonksiyonda 
                //sadece kategori düğümü sırala (bu kategorinin sıralandığı tek yer)
                //mevcut seçili kategori baz alınarak tüm harcama listesi tara (onaylananlar, geçici toplama dahil et, NULL'a ulaşınca direkt basıp sonraki kategori düğümüne geç aynısını yap, kategoride NULL'a ulaşınca döngüden çık)
                //boşalt ve çık
            }
            else {

            }
        }




        else {
            printf("komut taninmadi3\n");
            return 1;
        }
    }

}