#include <stdio.h>
#include "../include/queue.h"

int main() {
    Queue Q;
    CreateEmptyQueue(&Q, 3);
    if (IsQueueEmpty(Q)) printf("hadoh");
    printf("%d\n", MaxelQueue(Q));
    printf("%d\n", Head(Q));
    Add(&Q, 'P');
    printf("%c\n", InfoHead(Q));
    
}