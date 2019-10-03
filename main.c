#include "CDeck.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	for(i = 0; i < 8; i++){
		CardStyle = i;
		printf("  %d\n", CardStyle);
		printCardBack();
	}
	CardStyle = EMPTY;
	Card *d = calloc(52, sizeof(Card));
	getFullDeckTo(d);
	int size = 52;
	printCardsWithSplit(d, size, 4);
	free(d);
	return 0;
}
