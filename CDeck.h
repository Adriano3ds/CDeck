/*
 *		CDeck
 * 		by: Adriano Junior
 * 
*/

#ifndef _CDECK_H
#define _CDECK_H

const static char card_values_string[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J","Q","K"}; 
const static char card_suites_string[4][4] = {"\u2660", "\u2663","\u2665","\u2666"};

const static char card_styles_string[8][10] = {"   ", "\u2591\u2591\u2591", "\u2592\u2592\u2592", "\u2593\u2593\u2593", "\u2588\u2588\u2588", " \u2573 ", "\u2551\u2551\u2551", "\u256C\u256C\u256C"};

typedef enum card_suites{
	SPADES, CLUBS, HEARTS, DIAMONDS
} card_suites;

static card_suites ALL_SUITES[4] = { SPADES, CLUBS, HEARTS, DIAMONDS };

typedef enum card_styles{
	EMPTY, LIGHTSHADE, MEDIUMSHADE, DARKSHADE, FULLBLOCK, CROSS, PIPE, PIPECROSS
} card_styles;

card_styles CardStyle;

typedef struct Card{
	card_suites suite;
	int value;
} Card;

void getCardValueToString(int value, char *dest);
void getCardSuiteToString(card_suites suite, char *dest);
const char* getCardValue(Card c);
const char* getCardSuite(Card c);
void printCardBack();
void printCard(Card c);
void printCardsFromTo(Card deck[], int from, int to);
void printCards(Card deck[], int length);
void printCardsWithSplit(Card deck[], int length, int split);
void printCardValues(Card c, int newline);
void getFullDeckTo(Card deck[52]);
int createDeckWithFixedSize(Card deck[], int values[], int nvalues, card_suites suites[], int nsuites);
int createDeckWith(Card *deck, int *length, int values[], int nvalues, card_suites suites[], int nsuites);
int addCardsToDeck(Card **deck, int *length, Card cardsToAdd[], int ncards);
int removeIndexesFromDeck(Card **deck, int *length, int indexesToRemove[], int nindexes);
int removeCardsFromDeck(Card **deck, int *length, Card cardsToRemove[], int ncards);
void shuffleCards(Card deck[], int length, int probability);
void shuffleCardsNTimes(Card deck[], int length, int probabilities[], int n);

#endif
