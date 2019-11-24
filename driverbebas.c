
#include "../include/listlinier.h"
#include <stdio.h>

int main () {
    List l;
    CreateEmptyList(&l);
    InsVLast(&l, 'd');
    if (Search(l, 'd') != NULL) printf("yey");
    PrintInfo(l);
    return 0;


}