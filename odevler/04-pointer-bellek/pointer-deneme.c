#include <stdio.h>
#include <ctype.h>

void print_num_of_words_on_str(char * p)
{
    int word_cnt = 0;
    int is_space = 1;
    for (; *p != '\0';) {
        if (!isspace((unsigned char)*p) && is_space) {
            ++word_cnt;
            is_space = 0;
        }
        else if (isspace((unsigned char)*p)) {
            is_space = 1;
        }
        ++p;
    }
    printf("kelime sayisi = %d\n", word_cnt);
}



int main(void)
{
    // int sayi = 42;
    // int* p = &sayi;
    // printf("sayi = %d\np = %p\n", sayi, (void*)p);

    // *p = 99;
    // printf("sayi = %d\np = %p\n\n", sayi, (void*)p);
    

    char metin[] = "merhaba   dunya";
    // printf("metin dizisi: %p  %p  %p\n", metin, &metin[0], &metin);

    // printf("\n");
    // int dizi[] = {10, 20, 30, 40};
    // int* q = dizi;
    // printf("    q = %p\nq + 1 = %p\n", (void*)q, (void*)(q + 1));
    
    // printf("\n");
    
    // char* r = metin;
    // printf("    r = %p\nr + 1 = %p\n", (void*)r, (void*)(r + 1));

    print_num_of_words_on_str(metin);

}