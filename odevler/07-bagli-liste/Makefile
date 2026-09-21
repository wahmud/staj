kayit: main.o dosya.o kayit.o liste.o
	gcc -Wall -Wextra main.o dosya.o kayit.o liste.o -o kayit

main.o: main.c dosya.h kayit.h
	gcc -Wall -Wextra -c main.c

dosya.o: dosya.c dosya.h kayit.h
	gcc -Wall -Wextra -c dosya.c

kayit.o: kayit.c kayit.h
	gcc -Wall -Wextra -c kayit.c

liste.o: liste.c liste.h
	gcc -Wall -Wextra -c liste.c

clean:
	rm -f *.o kayit

fsanitize:
	gcc -Wall -Wextra -g -fsanitize=address -o kayit main.c liste.c dosya.c kayit.c