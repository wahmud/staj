#ifndef HARCAMA_H
#define HARCAMA_H

struct Kategoriler {
    char kategori[21];
    int toplam_tutar;
    struct Kategoriler* sonraki;
};
struct Harcamalar {
    char harcama[38];
    struct Harcamalar* sonraki;
};
int komut_dogrulama(int, char** argv);
int dosyadan_ekrana_basma(char* ay_tarihi);
int dosyadan_kategori_okuma_ve_siralama(struct Kategoriler**);
void kategori_ozeti_ekrana_basma(struct Kategoriler*);
int gecerli_kat_mi(char* kategori);
#endif
