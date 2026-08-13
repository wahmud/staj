1:  " wsl "                                             ---------       linuxa geçiş yapar.
2:  " gcc dosya.c -o dosya "                            ---------       dosyayı derler
3:  " gcc -Wall dosya.c -o dosya "                      ---------       dosyayı derlerken uyraı mesajlarını da aktif eder
4:  " ./dosya "                                         ---------       derlenmiş dosyayı çalıştırır
5:  " mv dosya.c klasor1/klasor2/dosya.c "              ---------       dosya.c'yi bu adrese taşır
6:  " mv dosya ../ "                                    ---------       dosyayı bir üste taşır
7:  " ls "                                              ---------       bulunduğumuz noktadaki dosyaların klasörlerin adını yazar
8:  " cd "                                              ---------       konumu terk eder
9:  " cd .. "                                           ---------       bir üste geçer
10: " cd klasörünadı "                                  ---------       eğer mevcutsa verilen konuma geçer.


--  git komutları: 

11: " git config --global user.name "kullanıcıadı" "    ---------       "kullanıcıadı" kısmını yazmazsan mevcut kayıtlı olan yazar, enter'e bastıktan sonra


12: " git config --global user.email "epostaadresi" "   ---------       "epostaadresi" kısmını yazmazsan mevcut kayıtlı olan yazar, enter'e bastıktan sonra


13: " git init "                                        ---------       Klasörde git'i başlatır, zaten başlatılmışsa sorun çıkarmaz


14: " git add "                                         ---------       Dosyaları staging'e ekleme ve dosya üstündeki değişiklikleri ekleme


15: " git restore --staged dosya "                      ---------       Ekleme'den çıkarmak için (staging area'dan)


16: " git restore --staged . "                          ---------       tüm dosyları çıkarmak için


00: " git restore dosya "                               ---------       Stage edilmemiş değişiklikleri geri döndürür, ve yerel olarak siler


17: " git commit -m "commit mesajı" "                   ---------       ile commit etme


18: " git remote add origin <adres> "                   ---------       repo için YENİ bir bağlama yapılacaksa


19: " git push "                                        ---------       gönderme


20: " git status "                                      ---------       nelerin değiştiğine bakma


21: " git ls-files "                                    ---------       sanırım, git'teki güncel ls durumu.


22: " git config --global --list "                      ---------       mevcut kullanıcı adı ve e postasını veriyor.


23: " git rm --cached dosya "                           ---------       dosyayı git takibinden çıkarmak için kullanılır.


00: " git rm dosya "                                    ---------       silinen dosyayı "silindi" olarak stage etmek için, yoksa git'te 
                                                                        kalmaya devam eder

24: " git show --stat (commit id) "                     ---------       Belirtilen commit'te yapılmış değişiklikleri verir.


00: " git mv eski-klasor/eski.txt yeni-klasor/yeni.txt "   ------       hem konumu hem dosya ismini değiştirip stage de eder.   


25: " git remote set-url origin https://wahmud:TOKENBURAYA@github.com/wahmud/staj.git "      -----------      Bu token sormamasını sağlıyor.


26: " git remote set-url origin https://github.com/wahmud/staj.git "                         -----------      Bu da tekrar kullanıcı adı ve 
                                                                                                              token istemesini sağlıyor.
