#include "mesinkata.h"
#include "../boolean/boolean.h"
#include "../utils/utils.h"
#include <stdio.h>

int angka(){
    int sum = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        sum = sum * 10 + (CKata.TabKata[j] - '0');
    }
    return sum;
}

int main () {
    STARTKATA();
    if (IsKataSama())
    // for(int i=1 ; i <= CKata.Length+2; i++) {
    //     // printf("%c\n", CKata.TabKata[i]);
    //     // printf("%c\n", kata[i]);
    //     printf("%c", CKata.TabKata[i]);
    // }
    printf("\n%c", CKata.TabKata[3]);
    // int n = angka();
    // while(n--){
    //     STARTKATA();
    //     int tmp = angka();
    //     printf("%d", tmp);
    // }
}
