#include "CDeck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void getCardValueToString(int value, char *dest){
	if (value < 1 || value > 13) return;
	*dest = *card_values_string[value-1];
}

void getCardSuiteToString(card_suites suite, char *dest){
	if (suite < 0 || suite > 3) return;
	*dest = *card_suites_string[suite];
}

const char* getCardValue(Card c){
	if(c.value < 1 || c.value > 13) return "";
	return card_values_string[c.value-1];
}

const char* getCardSuite(Card c){
	if(c.suite < 0 || c.suite > 3) return "";
	return card_suites_string[c.suite];
}

void printCardBack(){
	int i;
	const static char guide[42] = "\u250F\u2501\u2501\u2501\u2513\n\u2503sss\u2503\n\u2517\u2501\u2501\u2501\u251B\n";
	for(i = 0; guide[i]!='\0'; i++){
		if(guide[i] == 's'){
			printf("%s", card_styles_string[CardStyle]);
			i+=2;
		}else{
			printf("%c", guide[i]);
		}
	}
}

void printCard(Card c){
	if(c.value < 0 || c.value > 13) return;
	if(c.suite < 0 || c.suite > 3) return;
	int i;
	const static char guide[42] = "\u250F\u2501\u2501\u2501\u2513\n\u2503v s\u2503\n\u2517\u2501\u2501\u2501\u251B\n";
	for(i = 0; guide[i]!='\0'; i++){
		if(guide[i] == 'v'){
			if(c.value){
				printf("%s", getCardValue(c));
				if(c.value != 10)
					printf(" ");
			}else{
				if(CardStyle<0 || CardStyle > 7) CardStyle = EMPTY;
				printf("%s", card_styles_string[CardStyle]);
				i+=2;
			}
		}else if(guide[i] == 's'){
			printf("%s", getCardSuite(c));
		}else if(guide[i] == ' '){
		}else{
			printf("%c", guide[i]);
		}
	}
}

void printCardsFromTo(Card deck[], int from, int to){
	int rowIndex, cardIndex, colIndex;
	const static char guide[3][16] = {"\u250F\u2501\u2501\u2501\u2513", "\u2503v s\u2503", "\u2517\u2501\u2501\u2501\u251B"};
	for(rowIndex = 0; rowIndex < 3; rowIndex++){
		for(cardIndex = from; cardIndex < to; cardIndex++){
			if(deck[cardIndex].value < 0 || deck[cardIndex].value > 13) break;
			if(deck[cardIndex].suite < 0 || deck[cardIndex].suite > 3) break;
			for(colIndex = 0; guide[rowIndex][colIndex] != '\0'; colIndex++){
				if(guide[rowIndex][colIndex] == 'v'){
					if(deck[cardIndex].value){
						printf("%s", getCardValue(deck[cardIndex]));
						if(deck[cardIndex].value != 10)
							printf(" ");
					}else{
						if(CardStyle<0 || CardStyle > 7) CardStyle = EMPTY;
						printf("%s", card_styles_string[CardStyle]);
						colIndex+=2;
					}
				}else if(guide[rowIndex][colIndex] == 's'){
					printf("%s", getCardSuite(deck[cardIndex])); 
				}else if(guide[rowIndex][colIndex] == ' '){
				}else{
					printf("%c", guide[rowIndex][colIndex]);
				}
			}
		}
		printf("\n");
	}
}

void printCards(Card deck[], int length){
	printCardsFromTo(deck, 0, length);
}

void printCardsWithSplit(Card deck[], int length, int split){
	if(split >= length){
		printCards(deck, length);
		return;
	}
	if(split <= 0) return;
	int i;
	for(i = 0; i+split <= length; i+=split){
		printCardsFromTo(deck, i, i+split);
	}
	if(length%split != 0){
		printCardsFromTo(deck, i, length);
	}
}

void printCardValues(Card c, int newline){
	if(c.value < 1 || c.value > 13) return;
	if(c.suite < 0 || c.suite > 3) return;
	printf("%s%s", card_values_string[c.value-1], card_suites_string[c.suite]);
	if(newline) printf("\n");
}

void getFullDeckTo(Card deck[52]){
	int cardValue, cardSuite, cardIndex;
	for(cardValue = 1, cardIndex = 0; cardValue < 14; cardValue++){
		for(cardSuite = 0; cardSuite < 4; cardSuite++){
			deck[cardIndex].value = cardValue;
			deck[cardIndex].suite = (card_suites)cardSuite;
			cardIndex++;
		}
	}
}

int createDeckWithFixedSize(Card deck[], int values[], int nvalues, card_suites suites[], int nsuites){
	int cardIndex, valueIndex, suiteIndex;
	for(valueIndex = 0, cardIndex = 0; valueIndex < nvalues; valueIndex++){
		for(suiteIndex = 0; suiteIndex < nsuites; suiteIndex++){
			Card c = { suites[suiteIndex], values[valueIndex] };
			deck[cardIndex++] = c;
		}
	}
	return cardIndex;
}

int createDeckWith(Card *deck, int *length, int values[], int nvalues, card_suites suites[], int nsuites){
	deck = (Card *)realloc(deck, nvalues*nsuites*sizeof(Card));
	if(!deck) return 0;
	int cardIndex, valueIndex, suiteIndex;
	for(valueIndex = 0, cardIndex = 0; valueIndex < nvalues; valueIndex++){
		for(suiteIndex = 0; suiteIndex < nsuites; suiteIndex++){
			Card c = { suites[suiteIndex], values[valueIndex] };
			*(deck+cardIndex) = c;
			cardIndex++;
		}
	}
	*length = nvalues*nsuites;
	return 1;
}

int addCardsToDeck(Card **deck, int *length, Card cardsToAdd[], int ncards){
	Card *newDeck = calloc(*length + ncards, sizeof(Card));
	if(!newDeck) return 0;
	int i;
	for(i = 0; i < *length; i++)
		*(newDeck+i) = *((*deck)+i);
	for(i = 0; i < ncards; i++)
		*(newDeck+*(length)+i) = cardsToAdd[i];
	free(*deck);
	*deck = newDeck;
	*length += ncards;
	return 1;
}

int removeIndexesFromDeck(Card **deck, int *length, int indexesToRemove[], int nindexes){
	int cardIndex, newDeckIndex, removeIndex;
	Card *newDeck = calloc(*(length) - nindexes, sizeof(Card));
	if(!newDeck) return 0;
	for(cardIndex = 0, newDeckIndex = 0; cardIndex < *length; cardIndex++, newDeckIndex++){
		for(removeIndex = 0; removeIndex < nindexes; removeIndex++){
			if(cardIndex == indexesToRemove[removeIndex])
				cardIndex++;
		}
		*(newDeck+newDeckIndex) = *((*deck)+cardIndex);
	}
	free(*deck);
	*length -= nindexes;
	*deck = newDeck;
	return 1;
}

int removeCardsFromDeck(Card **deck , int *length, Card cardsToRemove[], int ncards){
	int cardIndex, cardToRemoveIndex, *ignoreIndexes = calloc(*length, sizeof(int)), j;
	if(!ignoreIndexes) return 0;
	for(cardIndex = 0, j = 0; cardIndex < *length; cardIndex++){
		for(cardToRemoveIndex = 0; cardToRemoveIndex < ncards; cardToRemoveIndex++){
			if(((*deck)+cardIndex)->value == cardsToRemove[cardToRemoveIndex].value && ((*deck)+cardIndex)->suite == cardsToRemove[cardToRemoveIndex].suite){
				*(ignoreIndexes+j) = cardIndex;
				j++;
			}
		}
	}
	Card **pdeck = deck;
	int res = removeIndexesFromDeck(pdeck, length, ignoreIndexes, j);
	free(ignoreIndexes);
	return res;
}

void shuffleCards(Card deck[], int length, int probability){
	if(probability >= 100 || probability <= 0) return;
	srand(time(NULL));
	int i, j;
	Card aux;
	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){
			if(rand()%100 + 1 <= probability){
				aux = deck[i];
				deck[i] = deck[j];
				deck[j] = aux;
			}
		}
	}
}

void shuffleCardsNTimes(Card deck[], int length, int probabilities[], int n){
	int i;
	for(i = 0; i < n; i++){
		shuffleCards(deck, length, probabilities[i]);
	}
}
