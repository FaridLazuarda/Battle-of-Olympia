#include "../include/utils.h"
#include <stdio.h>

boolean IsKataSama (char * a) {
    boolean ret = true;
    int i = 0;
    while (ret && i <= CKata.Length)
    {
        if (CKata.TabKata[i] != a[i]) {
            ret = false;
        }
        i++;
    }
    return ret;
}

int angka(){
    int sum = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        sum = sum * 10 + (CKata.TabKata[j] - '0');
    }
    return sum;
}

// int angkaLOAD(){
//     int sum = 0;
//     for (int j = 1; j <= CKataLOAD.Length; j++) {
//         sum = sum * 10 + (CKataLOAD.TabKata[j] - '0');
//     }
//     return sum;
// }

void printKata() {
    for(int i=1 ; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]);
    }
}

void NewGame() {
    
}