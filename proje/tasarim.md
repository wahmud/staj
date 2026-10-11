PROGRAMIN ADI: HARCAMA DEFTERİ


1.GEREKSİNİM LİSTESİ

KOMUTLAR:
./harcama ekle 05-10-2026 market 300       ------>        05-10-2026 kayıtlı "market" kategorisindeki 300 değerindeki harcama tutarını dosyaya ekler. Her komutta yalnıca bir adet harcama kaydı girilebilir.

./harcama liste 09-2026                    ------>        Eylül 2026 ayının tüm harcamalarını tarih sırasıyla basar, her satırda bir harcama.

./harcama ozet 09-2026                     ------>        Eylül 2026 ayı için tüm kategorileri ve kategorilerin toplam harcama tutarlarını  her satıra bir kategori ve onun toplamı olacak şekilde alfabetik sırayla basar



HATALI KOMUTLAR:
-"./harcama" ile başlamayan tüm komut girişimleri

-Sadece "./harcama"dan ibaret komut girişimi

-Harcama ekleme komutu için "./harcama"dan sonra gelen "ekle"den sonra 3 adet, ilki gg-aa-yyyy formatında tarih, ikincisi kategori, üçüncüsü numerik tutar olmak üzere boşluk karakterleri ile ayrılmış 3 adet giriş yapmamak.

-Harcamaları listeleme komutu için "./harcama"dan sonra gelen "liste"den sonra sadece senenin ayını belirten aa-yyyy formatında bir adet tarihsel giriş yapmamak.

-Kategorileri özetleme komutu için "./harcama"dan sonra gelen "ozet"ten sonra sadece senenin ayını belirten aa-yyyy formatında bir adet tarihsel giriş yapmamak.

-Tarih girişlerinde artık-sene olmayan senelerde 29 Şubat, veya 31 Nisan gibi gerçekte var olmayan herhangi bir tarihsel giriş yapmak

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
