PROGRAMIN ADI: HARCAMA DEFTERİ


1.GEREKSİNİM LİSTESİ

KOMUTLAR:
./harcama ekle 05-10-2026 market 300       ------>        05-10-2026 kayıtlı "market" kategorisindeki 300 değerindeki harcama tutarını dosyaya ekler. Her komutta yalnıca bir adet harcama kaydı girilebilir.

./harcama liste 09-2026                    ------>        Eylül 2026 ayının tüm harcamalarını tarih sırasıyla basar, her satırda bir harcama.

./harcama ozet 09-2026                     ------>        Eylül 2026 ayı için tüm kategorileri ve kategorilerin toplam harcama tutarlarını  alfabetik sırayla basar



HATALI KOMUTLAR:
-"./harcama" ile başlamayan tüm komut girişimleri

-Harcama ekleme komutu için "./harcama"dan sonra gelen "ekle"den sonra 3 adet, ilki gg-aa-yyyy formatında tarih, ikincisi kategori, üçüncüsü tutar olmak üzere boşluk karakterleri ile ayrılmış 3 adet giriş yapmamak.

-Harcamaları listeleme komutu için "./harcama"dan sonra gelen "liste"den sonra sadece senenin ayını belirten aa-yyyy formatında bir adet tarihsel giriş yapmamak.

-Kategorileri özetleme komutu için "./harcama"dan sonra gelen "ozet"ten sonra sadece senenin ayını belirten aa-yyyy formatında bir adet tarihsel giriş yapmamak.

-Tüm tarih girişlerinde artık-sene olmayan senelerde 29 Şubat, veya 31 Nisan gibi gerçekte var olmayan herhangi bir tarihsel giriş yapmak

-Tüm tarih girişlerinde rakam ve "-" tire karakteri haricinde herhangi bir karakter girişi yapmak

-Tüm tarih girişlerinde gelecek zaman veya 01-01-1800 tarihinden daha geri tarihleri girmek

-Tüm tarih girişlerinde 10 adetten fazla karakter girişi yapmak

-Harcama ekleme komutunda kategori için "market" harici bir kategori girişi yapmak

-Harcama ekleme komutunda tutar olarak negatif değer girmek

-Harcama ekleme komutunda tutar olarak sıfır değerini girmek.

-Harcama ekleme komutunda tutar olarak tamsayı haricinde gerçek sayı girişi yapmak

-Harcama ekleme komutunda tutar olarak 10.000 on bin'den fazla tutar girmek

-Tüm komutların tamamında büyük karakter kullanımı yapmak


KULLANILAN DOSYALAR:



PROGRAMIN YAPMADIKLARI:



2. PROGRAM DOSYALARI