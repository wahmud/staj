Windows'ta metin dosyalarında satır sonu \r\n olarak yazılır.

NOT: Windows'ta fopen("dosya.txt", "r") ile text mode açılan dosyalarda \r\n, okuma sırasında \n olarak çevrilir. rb (binary mode) kullanılırsa \r\n aynen okunur.(NOT: bu DÖNÜŞTÜRME Windows'ta oluyor, linux'ta falan olmuyor).