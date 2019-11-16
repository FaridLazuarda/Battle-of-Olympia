#include "../include/mesinkata.h"
#include "../include/boolean.h"
#include <stdio.h>

int main () {
    STARTKATA();
    for(int i=1 ; i <= CKata.Length; i++) {
        // printf("%c\n", CKata.TabKata[i]);
        // printf("%c\n", kata[i]);
        printf("%c", CKata.TabKata[i]);
    }
}