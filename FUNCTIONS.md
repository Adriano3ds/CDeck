# Functions

```C
void getCardValueToString(int value, char *dest);
```
This function saves the card value to a string. The output can be "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J","Q","K".



```C
void getCardSuiteToString(card_suites suite, char *dest);
```
This functions saves the card suite to a string. The output can be "♠", "♣", "♥", "♦".



```C
const char* getCardValue(Card c);
```
This function returns the card value as a string. The output can be "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J","Q","K".



```C
const char* getCardSuite(Card c);
```
This function returns the card suite as a string.  The output can be "♠", "♣", "♥", "♦".



```C
void printCardBack();
```
This function prints a card back. (See [CARDBACKS.txt](CARDBACKS.txt))



```C
void printCard(Card c);
```
This function prints a card. (See [CARD.txt](CARD.txt))

If the card value is 0, it will print the back of the card.



```C
void printCardsFromTo(Card deck[], int from, int to);
```
This function prints cards from index *from* to index *to* from the Card list *deck*.

If the card value is 0, it will print the back of the card.



```C
void printCards(Card deck[], int length);
```
This function prints all cards in the Card list *deck*, you need to pass the list length. Be careful, this functions does not check the maximum window width.

If the card value is 0, it will print the back of the card.



```C
void printCardsWithSplit(Card deck[], int length, int split);
```
This function prints all cards in the Card list *deck* splitting them by *split* cards each time, you need to pass the list length.

If the card value is 0, it will print the back of the card.



```C
void printCardValues(Card c, int newline);
```
This function prints the card value and suite as a string.



```C
void getFullDeckTo(Card deck[52]);
```
This function generates a full deck of cards (52 cards) to the Card list *deck*. The *deck* size must be 52.



```C
int createDeckWithFixedSize(Card deck[], int values[], int nvalues, card_suites suites[], int nsuites);
```
This function creates a card list in *deck* containing the values present in *values[]*, and the suites present in *suites[]* and return the size of the final *deck*. 

The return will be *nvalues* * *nsuites*.

This function uses a Card list. No memory allocation is used in here.

Note: you must pass the size of *values* and *suites*. 



```C
int createDeckWith(Card *deck, int *length, int values[], int nvalues, card_suites suites[], int nsuites);
```
This function creates a card list in *deck* containing the values present in *values[]*, and the suites present in *suites[]*. 

This function uses a Card pointer. Memory allocation is used in here. The new deck length will be set as the *length* value.

It returns 1 if ended successfully, or 0 if it failed to allocate memory.

Note: you must pass the size of *values* and *suites*.



```C
int addCardsToDeck(Card **deck, int *length, Card cardsToAdd[], int ncards);
```
This function will add cards in *cardsToAdd[]* to a Card pointer pointer *deck*. 

It returns 1 if ended successfully, or 0 if it failed to allocate memory.

Note: You must pass the number of cards to add.



```C
int removeIndexesFromDeck(Card **deck, int *length, int indexesToRemove[], int nindexes);
```
This function will remove the indexes in *indexesToRemove[]* from the Card pointer pointer *deck*. 

It returns 1 if ended successfully, or 0 if it failed to allocate memory.

Note: You must pass the number of indexes to remove.



```C
int removeCardsFromDeck(Card **deck, int *length, Card cardsToRemove[], int ncards);
```
This function will remove the Cards in *cardsToRemove[]* from the Card pointer pointer *deck*. 

It returns 1 if ended successfully, or 0 if it failed to allocate memory.

Note: You must pass the number of cards to remove.



```C
void shuffleCards(Card deck[], int length, int probability);
```
This function shuffles the Card list *deck*. 

The *probability* is the chance of the cards change their positions with each other. It must be inside the interval 0 < *probability* < 100.

Note: You must pass the number of cards in the *deck*.



```C
void shuffleCardsNTimes(Card deck[], int length, int probabilities[], int n);
```

This function shuffles the Card list *deck* as many times as the number of probabilities in *probabilities[]* (*n*). 

The *probabilities* is a list of probabilities, which is the chance of the cards change their positions with each other. It must be inside the interval 0 < *probability* < 100.

Note: You must pass the number of cards in the *deck* and the number of probabilities.
