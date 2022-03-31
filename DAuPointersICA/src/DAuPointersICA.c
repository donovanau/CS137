/*
 ============================================================================
 Name        : DAuPointersICA.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	//PROBLEM 1
	int numItems = 11;
	float price = 2.95;
	//TODO: create a pointer variable pNumItems that points to variable numItems
	int *pNumItems = &numItems;
	//TODO: create a pointer variable pPrice that points to variable price
	float *pPrice = &price;

	printf("The number of items is %d\n", numItems);
	printf("The price is %.2f\n", price);
	printf("The number of items is %d\n", *pNumItems);
	printf("The price is %.2f\n", *pPrice);

	//PROBLEM 2
	char phrase1[BUFSIZ];
	char phrase2[BUFSIZ];

	printf("Enter phrase 1:\n");
	fgets(phrase1, BUFSIZ, stdin);
	phrase1[strcspn(phrase1, "\n")] = 0;

	printf("Enter phrase 2:\n");
	fgets(phrase2, BUFSIZ, stdin);
	phrase2[strcspn(phrase2, "\n")] = 0;

	char *p = strstr(phrase1, phrase2);
	if (p == NULL) {
		printf("Phrase 1 does not contain phrase 2.\n");
	} else {
		printf("Phrase 1 contains phrase 2.\n");
	}

	int cmp = strcmp(phrase1, phrase2);
	if (cmp > 0) {
		printf("Phrase 1 is lexicographically greater than phrase 2.\n");
	}
	else if (cmp < 0) {
		printf("Phrase 1 is lexicographically less than phrase 2.\n");
	}
	else {
		printf("Phrase 1 is equal to phrase 2.\n");
	}

	return EXIT_SUCCESS;
}
