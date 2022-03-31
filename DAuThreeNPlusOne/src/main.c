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

//declare
int computeMaxSequenceLength(int firstVal, int lastVal); //iterates through range, returns max sequence
int computeSequenceLength(int n); //goes through a value of 'n' for sequence length, returns sequence of that
int computeNextValue(int n); //takes the value of n, and gets the next value?

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int maxSequence = 0;
	int firstVal, lastVal;
	char buffer[BUFSIZ];
	FILE *outputFile;

	printf("Enter output filename:\n"); //Prompts the user for an output filename.
	fgets(buffer, BUFSIZ, stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	outputFile = fopen(buffer, "w");

	//Here we must get 2 values from standard input:
	//the first and last value of the range
	//do not prompt.
	do {
		maxSequence = 0;
		firstVal = atoi(fgets(buffer, BUFSIZ, stdin));
		if (firstVal == 0) {
			break;
		}
		lastVal = atoi(fgets(buffer, BUFSIZ, stdin));
		if (lastVal == 0) {
			break;
		}

		maxSequence = computeMaxSequenceLength(firstVal, lastVal);

		fprintf(outputFile, "%d\t%d\t%d\n", firstVal, lastVal, maxSequence);
	} while (firstVal != 0); //what is the loop condition?
	printf("Complete\n");

	return EXIT_SUCCESS;
}

int computeMaxSequenceLength(int firstVal, int lastVal) {
	int fullCount = 0;
	int cmpCount = 0;
	for (int i = firstVal; i <= lastVal; i++) {
		cmpCount = computeSequenceLength(i);
		if (fullCount < cmpCount){
			fullCount = cmpCount;
		}
	}
	return fullCount;
}
int computeSequenceLength(int n) {
	int count = 0;
	while (n != 1) { //if 1 is passed, count = 0
		n = computeNextValue(n);
		count++;
	}
	count++; //output is off by 1 without.

	return count;
}
int computeNextValue(int n) {
	if (n % 2 == 0) {
		n = n / 2;
	} else {
		n = n * 3 + 1;
	}
	return n;
}
