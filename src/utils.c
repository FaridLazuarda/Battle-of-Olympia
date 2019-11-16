#include "../include/utils.h"

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