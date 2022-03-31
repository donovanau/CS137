/*
 ============================================================================
 Name        : main.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	char filename[BUFSIZ];
	char c;
	int numA = 0, numC = 0, numG = 0, numT = 0;
	FILE *inputFile;
	FILE *outputFile;

	printf("Enter input filename:\n"); //Prompts the user for an input filename.
	fgets(filename,BUFSIZ,stdin);
	filename[strcspn(filename, "\n")] = 0;
	inputFile = fopen(filename, "r");

	printf("Enter output filename:\n"); //Prompts the user for an output filename.
	fgets(filename,BUFSIZ,stdin);
	filename[strcspn(filename, "\n")] = 0;
	outputFile = fopen(filename, "w");

	if (inputFile) { //check if file exists
		while (!feof(inputFile)) {
			c = fgetc(inputFile);
			switch (c) {
			case 'A':
			case 'a':
				numA++;
				break;
			case 'C':
			case 'c':
				numC++;
				break;
			case 'G':
			case 'g':
				numG++;
				break;
			case 'T':
			case 't':
				numT++;
				break;
			case '\n':
				fprintf(outputFile, "%d %d %d %d\n", numA, numC, numG, numT);
				numA = numC = numG = numT = 0;
			}
		}
	}

	fclose(outputFile);
	fclose(inputFile);

	printf("Complete\n");

	return EXIT_SUCCESS;
}
