// Nama 	: Annisa Ayu Pramesti
// NIM		: 13518085
// Tanggal	: 24 Oktober 2019

#include <stdio.h>
#include "listlinier.h"

int main() {
	int n, num, step, trash;
	address search;
	List L;
	CreateEmpty(&L);
	scanf("%d", &n);
	scanf("%d", &num);
	for (int i = 1; i <= n; i++) {
		InsVLast(&L, i);
	}
	for (int i = 1; i <= num; i++) {
		scanf("%d", &step);
		search = Search(L, step);
		
		if (search != Nil) {
			DelP(&L, step);
			InsVFirst(&L, step);
			printf("hit ");
			PrintInfo(L);
		} else { // kalo ga ada
			printf("miss ");
			DelVLast(&L, &trash);
			InsVFirst(&L, step);
			PrintInfo(L);
		}
		printf("\n");
	}
	return 0;
}
