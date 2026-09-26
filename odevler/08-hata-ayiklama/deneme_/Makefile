kayit: main.o dosya.o kayit.o liste.o
	gcc -g -Wall -Wextra kayit.o liste.o dosya.o main.o -o kayit

kayit.o: kayit.c kayit.h
	gcc -g -Wall -Wextra -c kayit.c

liste.o: liste.c liste.h kayit.h
	gcc -g -Wall -Wextra -c liste.c

dosya.o: dosya.c dosya.h kayit.h liste.h
	gcc -g -Wall -Wextra -c dosya.c

main.o: main.c dosya.h kayit.h liste.h
	gcc -g -Wall -Wextra -c main.c

clean:
	rm -f *.o kayit

fsanitize:
	gcc -Wall -Wextra -g -fsanitize=address -o kayit main.c liste.c dosya.c kayit.c