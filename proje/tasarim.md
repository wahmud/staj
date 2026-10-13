PROGRAMIN ADI: HARCAMA DEFTERİ


1.GEREKSİNİM LİSTESİ

KOMUTLAR:
./harcama ekle 05-10-2026 market 300       ------>        05-10-2026 kayıtlı "market" kategorisindeki 300 değerindeki harcama tutarını dosyaya ekler. Her komutta yalnıca bir adet harcama kaydı girilebilir.

./harcama liste 09-2026                    ------>        Eylül 2026 ayının tüm harcamalarını tarih sırasıyla basar, her satırda bir harcama.

./harcama ozet 09-2026                     ------>        Eylül 2026 ayı için tüm kategorileri ve kategorilerin toplam harcama tutarlarını  her satıra bir kategori ve onun toplamı olacak şekilde alfabetik sırayla basar



HATALI KOMUTLAR:
-"./harcama" ile başlamayan tüm komut girişimleri

-Sadece "./harcama"dan ibaret komut girişimi

-Tüm komutlarda çift tırnak içinde boşluk karakterleri kullanmak

-Harcama ekleme komutu için "./harcama"dan sonra gelen "ekle"den sonra 3 adet, ilki gg-aa-yyyy formatında tarih, ikincisi kategori, üçüncüsü numerik tutar olmak üzere boşluk karakterleri ile ayrılmış 3 adet giriş yapmamak.

-Harcamaları listeleme komutu için "./harcama"dan sonra gelen "liste"den sonra sadece senenin ayını belirten aa-yyyy formatında bir adet tarihsel giriş yapmamak.

-Kategorileri özetleme komutu için "./harcama"dan sonra gelen "ozet"ten sonra sadece senenin ayını belirten aa-yyyy formatında bir adet tarihsel giriş yapmamak.

-Tarih girişlerinde artık-sene olmayan senelerde 29 Şubat, veya 31 Nisan gibi takvimde var olmayan herhangi bir tarihsel giriş yapmak

-Tüm tarih girişlerinde rakam ve tire "-" karakteri haricinde herhangi bir karakter girişi yapmak

-Tüm tarih girişlerinde gelecek zaman veya 01-01-1800 tarihinden daha geri tarihleri girmek

-Tüm tarih girişlerinde 10 adetten fazla karakter girişi yapmak

-Harcama ekleme komutunda kategori için 20'den fazla karakter ve boşluk ile ayrılmış giriş yapmak

-Harcama ekleme komutunda tutar olarak negatif değer girmek

-Harcama ekleme komutunda tutar olarak sıfır değerini girmek.

-Harcama ekleme komutunda tutar olarak tamsayı haricinde gerçek sayı girişi yapmak

-Harcama ekleme komutunda tutar olarak 10.000 on bin'den fazla tutar girmek

-Kategori hariç tüm komutların tamamında büyük harf kullanımı yapmak



KULLANILAN DOSYA(LAR):
harcamalar.txt:
(Örnek 2 satır):
07-10-2026 market 1000
08-10-2026 market 200

Dosya mevcut değilse, dosya ekleme komutu ile bir harcama eklenene kadar, listeleme ve kategori özetleme komutları Dosya yok hatası verir.



PROGRAMIN YAPMADIKLARI:
-Günün kategori özetini vermez.
-Günün toplam harcamasını vermez.
-Bir senelik kategori özetini vermez.
-Bir senelik toplam harcamayı vermez.
-O ana kadarki kategori özetini vermez.
-O ana kadarki toplam harcamayı vermez.
-Aynı anda birden fazla harcama kaydı girişi almaz.
-Tam sayı harici gerçek sayı tutar girişi almaz.
-Kateogri girişi hariç komutlarda büyük harf toleransı yoktur.
-Ay içinde INT_MAX'ı aşan toplam tutarlarda, listeleme ve kategori özetleme komutları hatalı sonuç verir ve hata mesajı vermez.
-Tarih girişlerinde ayıraç olarak tire "-" karakteri haricinde herhangi bir ayıraç kabul etmez.
-Herhangi bir silme işlemi yapmaz.


2. PROGRAM DOSYALARI
dosya.h:
    int kayitlari_oku_har(struct Harcamalar**);
    int kayitlari_yaz(struct Harcamalar*);
    int kayitlari_oku_kat(struct Kategoriler**);
dosya.c
    kayitlari_oku_har:
        -1 malloc'un başarısız olduğunu bildirir
    kayitlari_oku_kat:
        -1 dugum_ekle_kat'ın malloc'unun başarısız olduğunu bildirir
    kayitlari_yaz:
        1 dosyanın açılamadığını bildirir


harcama.h:
    int komut_dogrulama(int, char**);
    int dosyadan_ekrana_basma(char*);
    ozetleme_komutu_icin_dosyadan_okurken_dugum_kat_doldurup_siralayip_denetim_yapip_dugum_kattaki_toplam_tutari_dolduran_fonksiyon_adi(struct Kategoriler**);
    void ozetleme_komutu_icin_dugum_kat_basma_fonksiyon_adi(struct Kategoriler*);
    int gecerli_kat_mi(char*);

harcama.c:
    komut_dogrulama:
        1  ekle komutunun çağırıldığını bildirir
        11 ekle komutunun 1 numaralı hatasını bildirir, gecerli_gun_tarihi_mi'nin false döndürdüğünü bildirir
        12 ekle komutunun 2 numaralı hatasını bildirir, gecerli_kat_mi'nin false döndürdüğünü bildirir
        13 ekle komutunun 3 numaları hatasını bildirir
        14 ekle komutunun 4 numaralı hatasını bildirir
        15 ekle komutunun 5 numaralı hatasını bildirir
        16 ekle komutunun 6 numaralı hatasını bildirir
        17 ekle komutunun 7 numaralı hatasını bildirir
        2  liste komutunun çağırıldığını bildirir
        21 liste komutunun 1 numaralı hatasını bildirir, gecerli_ay_tarihi_mi'nin false döndürdüğünü bildirir
        3  ozet komutunun çağırıldığını bildirir
        31 ozet komutunun 1 numaralı hatasını bilrdirir, gecerli_ay_tarihi_mi'nin false döndürdüğünü bildirir
        0 tanımlı olmayan komut çağrısını bildirir
        -1 -1 numaralı hatayı bildirir
    dosyadan_ekrana_basma:
        -1 dosyanın açılamadığını bildirir
        0 verilen tarih ile alakalı bir kayıt olmadığını bildirir

    ozetleme_komutu_icin_dosyadan_okurken_dugum_kat_doldurup_siralayip_denetim_yapip_dugum_kattaki_toplam_tutari_dolduran_fonksiyon_adi:
        1 dosyanın açılamadığını bildirir
        -1 kayitlari_oku_kat'ın malloc'unun başarısız olduğunu bildirir
        2 dosyanın boş olduğunu bildirir

    ozetleme_komutu_icin_dugum_kat_basma_fonksiyon_adi:
        dönüş değeri yok

    gecerli_kat_mi:
        0 kriterlere uygun olmayan kategori girişini bildirir
        1 kriterlere uygun olan kategori girişini bildirir


liste.h:
    struct Harcamalar* dugum_ekle_har(struct Harcamalar**, char*);
    struct Kategoriler* dugum_ekle_kat(struct Kategoriler**, struct Kategoriler*);
    void liste_bosalt_har(struct Harcamalar**);
    void liste_bosalt_kat(struct Kategoriler**);
    void liste_sirala_har(struct Harcamalar**);
    void liste_sirala_kat(struct Kategoriler**);
    struct Kategoriler* liste_ara(struct Kategoriler* bas, char* ad);

liste.c:
    dugum_ekle_har:
        NULL malloc'un başarısız olduğunu bildirir
    dugum_ekle_kat:
        NULL malloc'un başarızı olduğunu bildirir
    liste_bosalt_har:
        dönüş değeri yok
    liste_bosalt_kat:
        dönüş değeri yok
    liste_sirala_har:
        dönüş değeri yok
    liste_sirala_kat:
        dönüş değeri yok
    liste_ara:
        bulduğu kategori bağlı listesine ait düğüm adresini döndürür


tarih.h:
    #define  isleap(x)  (x%4 == 0  ?  (x%100 == 0  ?  x%400 == 0  :  1)  :  0)
    int is_real_date(int, int, int);
    int gecerli_gun_tarihi_mi(char*);
    int gecerli_ay_tarihi_mi(char*);

tarih.c:
    is_real_date:
        0 yanlış takvim tarihi girildiğini bildirir
        1 doğru takvim tarihi girildiğini bildirir
    gecerli_gun_tarihi_mi:
        0 kriterlere uygun olmayan tarih girişi olduğunu bildirir
        1 kriterlere uygun olan tarih girişi olduğunu bildirir
    gecerli_ay_tarihi_mi:
        0 kriterlere uygun olmayan ay tarihi girişi olduğunu bildirir
        1 kriterlere uygun olan ay tarihi girişi olduğunu bildirir

main.c:
    tüm program buradan yürütülür