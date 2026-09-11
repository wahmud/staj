kayit: main.o dosya.o kayit.o
	gcc -Wall -Wextra main.o dosya.o kayit.o -o kayit

main.o: main.c dosya.h kayit.h
	gcc -Wall -Wextra -c main.c

dosya.o: dosya.c dosya.h kayit.h
	gcc -Wall -Wextra -c dosya.c

kayit.o: kayit.c kayit.h
	gcc -Wall -Wextra -c kayit.c

clean:
	rm -f *.o kayit