harcama: main.o harcama.o dosya.o liste.o tarih.o
	gcc -g -Wall -Wextra main.o harcama.o dosya.o liste.o tarih.o -o harcama

main.o: main.c harcama.h dosya.h liste.h tarih.h
	gcc -g main.c -c

harcama.o: harcama.c harcama.h dosya.h liste.h tarih.h
	gcc -g harcama.c -c

dosya.o: dosya.c harcama.h dosya.h liste.h tarih.h
	gcc -g dosya.c -c

liste.o: liste.c harcama.h liste.h
	gcc -g liste.c -c

tarih.o: tarih.c tarih.h
	gcc -g tarih.c -c