#include "../include/matriks.h"
#include <stdio.h>

int main() {
    MATRIKS M1, M2;

    BacaMATRIKS(&M1, 3, 3);
    CopyMATRIKS(M1, &M2);
    TulisMATRIKS(M2);
    
    
    
    
    return 0;
}