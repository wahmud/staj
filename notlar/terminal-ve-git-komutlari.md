1:  " wsl ", linuxa geçiş yapar.
2:  " gcc dosya.c -o dosya " , dosyayı derler
3:  " gcc -Wall dosya.c -o dosya " dosyayı derlerken uyraı mesajlarını da aktif eder
4:  " ./dosya " derlenmiş dosyayı çalıştırır
5:  " mv dosya.c klasor1/klasor2/dosya.c " dosya.c'yi bu adrese taşır
6:  " mv dosya ../ " dosyayı bir üste taşır
7:  " ls " bulunduğumuz noktadaki dosyaların klasörlerin adını yazar
8:  " cd " konumu terk eder
9:  " cd .. " bir üste geçer
10: " cd klasörünadı " eğer mevcutsa verilen konuma geçer.


--  git komutları: 

11: " git config --global user.name "kullanıcıadı" "        ---------       "kullanıcıadı" kısmını yazmazsan mevcut kayıtlı olan yazar, enter'e bastıktan sonra


12: " git config --global user.email "epostaadresi" "       ---------       "epostaadresi" kısmını yazmazsan mevcut kayıtlı olan yazar, enter'e bastıktan sonra


13: " git init "          klasörde git'i başlatır, zaten varsa da sorun olmaz


14: " git add "          ile dosyaları ekleme


00: " git restore --staged dosya "    ekleme'den çıkarmak için (staging area'dan)


00: " git restore --staged . "    tüm dosyları çıkarmak için


15: " git commit -m "commit mesajı" "        ile commit etme


16: " git remote add origin <adres> "           repo için YENİ bir bağlama yapılacaksa


17: " git push "             gönderme


18: " git status "         nelerin değiştiğine bakma


19: " git ls-files "          sanırım, git'teki güncel ls durumu.


20: " git config --global --list "        mevcut kullanıcı adı ve e postasını veriyor.


21: " git remote set-url origin https://wahmud:TOKENBURAYA@github.com/wahmud/staj.git "      -----------      Bu token sormamasını sağlıyor.


22: " git remote set-url origin https://github.com/wahmud/staj.git "                         -----------      Bu da tekrar kullanıcı adı ve token istemesini sağlıyor.


23: " git rm --cached dosya "     ----    dosyayı git takibinden çıkarmak için kullanılır.