#ifndef KAYIT_H
#define KAYIT_H

struct Kayit {
    char ad[41];
    int yas;
    char tarih[11];
};

void* kayit_realloc(struct Kayit** p, int size);
char* kayit_fgets(char* temp, int size);

#endif 