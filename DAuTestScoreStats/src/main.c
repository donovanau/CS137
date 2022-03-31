/*
 ============================================================================
 Name        : DAuTestScoreStats.c
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
	setvbuf(stdout, NULL, _IONBF, 0);
	float sum = 0, input, min, max, avg, sumSquares = 0, stDev; //is this too many variables?
	int count = 0;

	char buffer[BUFSIZ];

	puts("Enter scores, one per line.  Press <ENTER> on a blank line to end."); //Prompts the user.
	do {
		fgets(buffer, BUFSIZ, stdin);
		input = atof(buffer);

		sum += input;
		sumSquares += input * input;

		if (input != 0.0) {		//if i dont do this, avg will be "-NaN" (for no scores) and min will always be 0.0
			count++;			//not sure if there's a better way to do this for counting
			if (input < min || count == 1) {
				min = input;
			}
			if (input > max || count == 1) {
				max = input;
			}
			avg = sum / count;											// the problem with this is it does the
																		// calculation every time a score is entered
			stDev = sqrt((sumSquares - (pow(sum, 2) / count)) / count);	// should be fine for this assignment though.
		}

	} while (input > 0.0);

	printf("%d\t%f\t%f\t%f\t%f\n", count, min, max, avg, stDev);

	return EXIT_SUCCESS;
}
