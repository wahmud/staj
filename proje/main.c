#include <stdio.h>
#include <string.h>
#include "harcama.h"
#include "dosya.h"
#include "tarih.h"
#include "liste.h"

int main(int argc, char* argv[])
{
    struct Kategoriler* dugum_kat;
    struct Harcamalar* dugum_har;
    int komut_id = komut_dogrulama(argc, argv);
    if (komut_id == 1) {
        //dosyadan oku
        int kayitlari_oku_ret = kayitlari_oku_har(&dugum_har);
        if (kayitlari_oku_ret == -1) {
            printf("Bellek Alani Eklenemedi\n");
            liste_bosalt_har(&dugum_har);
            return 1;
        }
        //bitti

        //yeni harcamayı ekle
        char temp_harcama[38] = "";
        strcat(temp_harcama, argv[2]);
        strcat(temp_harcama, argv[3]);
        strcat(temp_harcama, argv[4]);
        
        struct Harcamalar* dugum_ekle_ret = dugum_ekle_har(&dugum_har, temp_harcama);
        if (!dugum_ekle_ret) {
            printf("Bellek alani eklenemedi\n");
            liste_bosalt_har(&dugum_har);
            return 1;
        }
        //bitti

        //sırala
        liste_sirala_har(&dugum_har);
        //bitti

        //dosyaya yaz
        int yazma_ret = kayitlari_yaz(dugum_har);
        if (yazma_ret == 1) {
            printf("Dosya acilamadi\n");
            liste_bosalt_har(&dugum_har);
            return 1;
        }
        //bitti

        //boşalt ve çık
        liste_bosalt_har(&dugum_har);
        return 0;
        //bitti
    }
    
    else if (komut_id == 11) {
        printf("Hatali Tarih Girisi\n");
            return 1;
    }
    else if (komut_id == 12) {
        printf("Girilen Kategori Kriterlere Uygun Degil. Yeniden Deneyin\n");
        return 1;
    }
    else if (komut_id == 13) {
        printf("Sayi Girisinde Hata\n");
        return 1;
    }
    else if (komut_id == 14) {
        printf("Tutar Girisi Tam Sayi Olmali\n");
        return 1;
    }
    else if (komut_id == 15) {
        printf("Tutar Olarak Sifirdan Farkli Olmali\n");
        return 1;
    }
    else if (komut_id == 16) {
        printf("Tutar Girisi Negatif Deger Olamaz\n");
        return 1;
    }
    else if (komut_id == 17) {
        printf("10.000'den Yuksek Tutar Girisi Yapilamaz\n");
        return 1;
    }
    


    
    if (komut_id == 2) {
            int okuyup_basma_ret = dosyadan_ekrana_basma(argv[2]);
            if (okuyup_basma_ret == -1) {
                printf("Dosya Acilamadi\n");
                return 1;
            }
            else if (okuyup_basma_ret == 0) {
                printf("Girilen Ay Icin Harcama Kaydi Yok\n");
            }
    }
    else if (komut_id == 21) {
        printf("Gecerli Bir Ay Tarihi Girilmedi\n");
        return 1;
    }




    if (komut_id == 3) {
            int toplam_hesaplama_ret = dosyadan_kategori_okuma_ve_siralama(&dugum_kat);
            if (toplam_hesaplama_ret == 1) {
                printf("Dosya Acilamadi\n");
                return 1;
            }
            else if (toplam_hesaplama_ret == -1) {
                printf("Bellek Yetersiz\n");
                liste_bosalt_kat(&dugum_kat);
                return 1;
            }
            else if (toplam_hesaplama_ret == 2) {
                printf("Dosya Bos\n");
                return 1;
            }
            kategori_ozeti_ekrana_basma(dugum_kat);
            liste_bosalt_kat(&dugum_kat);
            return 0;
    }
    else if (komut_id == 31) {
        printf("Gecerli Bir Ay Tarihi Girilmedi\n");
        return 1;
    }

    else if (komut_id == 0){
            printf("Komut Taninmadi\nEkleme Komutu icin:             ./harcama ekle gg-aa-yyyy [kategori] [sayi]\nListeleme Komutu Icin:          ./harcama liste aa-yyyy\nKategori Ozetleme Komutu Icin:  ./harcama ozet aa-yyyy\n");
            return 1;
    }
    else if (komut_id == -1) {
        printf("Cift Tirnak Icinde Bosluk Karakterleri Kullanilamaz\n");
        return 1;
    }


}