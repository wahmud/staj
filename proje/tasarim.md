PROGRAMIN ADI: HARCAMA DEFTERİ


1.GEREKSİNİM LİSTESİ

KOMUTLAR:
./harcama ekle 05-10-2026 market 300       ------>        05-10-2026 kayıtlı "market" kategorisindeki 300 değerindeki harcama tutarını dosyaya ekler. Her komutta yalnıca bir adet harcama kaydı girilebilir.

./harcama liste 09-2026                    ------>        Eylül 2026 ayının tüm harcamalarını tarih sırasıyla basar, her satırda bir harcama.

./harcama ozet 09-2026                     ------>        Eylül 2026 ayı için tüm kategorileri ve kategorilerin toplam harcama tutarlarını  her satıra bir kategori ve onun toplamı olacak şekilde alfabetik sırayla basar



HATALI KOMUTLAR:
-Sadece "./harcama"dan ibaret komut girişimi için "Komut girilmedi"

-./harcama'dan sonra ekle, liste, ozet harici bir girdi yapma için "Komut taninmadi"

-Ekleme komutunda "ekle"de büyük harf kullanma (örn. EKLE) için "Komut Taninmadi"
-Ekleme komutu için ekle'den sonra 3 adet giriş yapmamak:
    -0 adet giriş için "Tarih Girilmedi"
    -1 adet giriş için "Kategori girilmedi
    -2 adet giriş için "Tutar Girilmedi"
-Ekleme komutu için geçersiz girişler yapmak:
    -Tarih için takvimde bulunmayan ve gelecek zaman ve 1800 yılından geri tarih girmek ve 10 adetten fazla karakter girmek ve rakam-tire karakterleri haricinde herhangi bir karakter girişi yapmak; durumlarının her biri için "Geçersiz Tarih Girildi"
    -Kategori için 20 adet karakterden büyük giriş yapmak ve boşluk karakterli kategori ismi vermeye çalışmak durumları için "Gecersiz Kategori Girildi"
    -Tutar için negatif değer girmek için "Tutar Negatif Olamaz"
    -Tutar için sıfır değerini girmek için "Tutar 0 Olamaz"
    -Tutar için tam sayı harici gerçek sayı girmek için "Tutar Gercek Sayi Olamaz"
    -Tutar için 10.000 değerini geçen tutar girmek için "Tutar 10.000'den Fazla Olamaz"
-NOT: Ekleme komutunda tüm girişlerin geçersiz olması durumunda sadece ilk tespit edilen kısım için hata mesajı verilir devamına bakılmaz.

-Listeleme komutunda "liste"de büyük harf kullanma için "Komut Taninmadi"
-Listeleme komutu için liste'den sonra 1 adet giriş yapmama için "Tarih Girilmedi"
-Listeleme komutunda için takvimde bulunmayan ve gelecek zaman ve 1800 yılından geri tarih girmek ve 7 adetten fazla karakter girmek ve rakam-tire karakterleri haricinde herhangi bir karakter girişi yapmak; durumlarının her biri için "Geçersiz Tarih Girildi"

-Özetleme komutunda "ozet"te büyük harf kullanma için "Komut Taninmadi"
-Özetleme komutu için ozet'ten sonra 1 adet giriş yapmama için "Tarih Girilmedi"
-Özetleme komutunda için takvimde bulunmayan ve gelecek zaman ve 1800 yılından geri tarih girmek ve 7 adetten fazla karakter girmek ve rakam-tire karakterleri haricinde herhangi bir karakter girişi yapmak; durumlarının her biri için "Geçersiz Tarih Girildi"

-Tüm komutlarda çift tırnak içinde boşluk karakterleri kullanma için "Cift Tirnak Icinde Bosluk Karakteri Kullanılamaz"

-"Komut Taninmadi" ve "Komut Girilmedi" durumlarında programın nasıl çalıştığının gösterimi:
"Ekleme Komutu icin: ./harcama ekle gg-aa-yyyy [kategori] [sayi]
Listeleme Komutu Icin: ./harcama liste aa-yyyy
Kategori Ozetleme Komutu Icin: ./harcama ozet aa-yyyy"


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
    int dosyadan_oku_har(struct Harcamalar**);
    int dosyadan_oku_kat(struct Kategoriler*, char*);
    int dosyaya_yaz(struct Harcamalar*);
    int dosyadan_ekrana_basma(char*);
dosya.c
    int dosyadan_oku_har(struct Harcamalar** bas_pointer);
        -Dosyadan Harcamalar yapısını kullanarak bağlı liste olarak belleğe okur.
    int dosyadan_oku_kat(struct Kategoriler* dugum, char* ay_tarihi);
        -Dosyadan Kategoriler yapısını kullanarak bağlı liste olarak belleğe okur, ek olarak argüman verilen ay-tarihini de kontrol eder.
    int dosyaya_yaz(struct Harcamalar* dugum);
        -Harcamalar yapısndan oluşturulan bağlı listeyi dosyaya yazar.
    int dosyadan_ekrana_basma(char* ay_tarihi);
        -Dosyadaki satırları ekrana basar, ay-tarihini kontrol eder.



harcama.h:
    int komut_dogrulama(int, char**);
    void hata_mesaji_basma(int);
    int gecerli_kat_mi(char* kategori);
    int gecerli_gun_tarihi_mi(char* tarih);
    int gecerli_ay_tarihi_mi(char* tarih);

harcama.c:
    int komut_dogrulama(int argc, char** argv);
        -Komutun geçerliliğini kontrol eder, dönüş değeri ile durumu belirtir.
    void hata_mesaji_basma(int hatali_komut);
        -Komut hatasını ekrana basar.
    int gecerli_kat_mi(char* kategori);
        -Kategorinin geçerli olup olmadığını kontrol eder.
    int gecerli_gun_tarihi_mi(char* tarih);
        -Tarihin geçerli olup olmadığını kontrol eder.
    int gecerli_ay_tarihi_mi(char* tarih);
        -Ay-tarihinin geçerli olup olmadığını kontrol eder.



liste.h:
    struct Harcamalar {
        char tarih[11];
        char kategori[21];
        int tutar;
        struct Harcamalar* sonraki;
    };
    struct Kategoriler {
        char kategori[21];
        int toplam;
        struct Kategoriler* sonraki;
    };
    struct Harcamalar* dugum_ekle_har(struct Harcamalar**, struct Harcamalar harcamalar);
    struct Kategoriler* dugum_ekle_kat(struct Kategoriler**);
    void liste_bosalt_har(struct Harcamalar**);
    struct Kategoriler* liste_bosalt_kat(struct Kategoriler**);
    void liste_tarihsel_sirala(struct Harcamalar**);
    void liste_kategori_sirala(struct Kategoriler**);
    int kategori_toplamlari_ekle(struct Kategoriler*, char*);
    struct Kategoriler* liste_ara(struct Kategoriler*, char*);
    void liste_ozet_bas(struct Kategoriler*);

liste.c:
    struct Harcamalar* dugum_ekle_har(struct Harcamalar** bas_pointer, struct Harcamalar harcamalar);
        -Harcamalar yapısının bağlı listesinin sonuna yeni düğüm ekler, veya ilk düğümü doldurur.
    struct Kategoriler* dugum_ekle_kat(struct Kategoriler** bas_pointer);
        -Kategoriler yapısının bağlı listesinin sonuna yeni düğüm ekler, veya ilk düğümü doldurur.
    void liste_bosalt_har(struct Harcamalar** bas_pointer);
        -Harcamalar yapısının bağlı listesini tamamen free eder.
    void liste_bosalt_kat(struct Kategoriler** bas_pointer);
        -Kategoriler yapısının bağlı listesini tamamen free eder.
    void liste_tarihsel_sirala(struct Harcamalar** bas_pointer);
        -Harcamalar yapısının bağlı listesinin düğümlerini tarihsel olarak sıralar.
    void liste_kategori_sirala(struct Kategoriler** bas_pointer);
        -Kategori bağlı listesinin düğümlerini kategori dizisine göre alfabetik sıralar.
    int kategori_toplamlari_ekle(struct Kategoriler* dugum, char* ay_tarihi);
        -Dosyadan okuduğu satırdaki tutarı ilgili kategori düğümünün toplam elemanına ekler, ay-tarihini kontrol eder.
    struct Kategoriler* liste_ara(struct Kategoriler* dugum, char* kategori);
        -Kategori bağlı listesinde aranan düğümü bulur ve adresini döndürür.
    void liste_ozet_bas(struct Kategoriler*);
        -Kategori bağlı listesini ekrana basar.




tarih.h:
    #define  isleap(x)  (x%4 == 0  ?  (x%100 == 0  ?  x%400 == 0  :  1)  :  0)
    int is_real_date(int gun, int ay, int yil);

tarih.c:
    int is_real_date(int gun, int ay, int yil);
        -Girilen gün ay ve yıl değerlerinin takvimde geçerli bir tarihi ifade edip etmediğini kontrol eder.



main.c:
    Tüm program buradan yürütülür.