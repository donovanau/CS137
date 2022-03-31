/*
 ============================================================================
 Name        : DAuLoopsICA.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int i;
	int y;

	for (i = 0; i <= 10; i = i + 1) {
		y = pow(2, i);
		printf("2^%d = %d\n", i, y);
	}

	puts(""); //newline

	char name[BUFSIZ] = "";

	do {
		puts("Please input your name!");
		fgets(name, BUFSIZ, stdin);
		printf(name);
	} while (name[0] == '\n');

	return EXIT_SUCCESS;
}
