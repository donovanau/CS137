/*
 ============================================================================
 Name        : FunctionsICA.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : Functions In Class Assignment
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//declarations
float computeArea(float length, float width);
float computePerimeter(float length, float width);
float computeDiagonal(float length, float width);
float computeValue(float area, int locationType);

int main(void) {
	float length = 0, width = 0, area = 0, perimeter = 0, diagonal = 0, value = 0;
	int location;
	char buffer[BUFSIZ];

	//Prompt user for these variables
	printf("Enter a width (m): \n");\
	width = atof(fgets(buffer, BUFSIZ, stdin));
	printf("Enter a length (m): \n");\
	length = atof(fgets(buffer, BUFSIZ, stdin));
	printf("Enter a location (1 = city, 2 = suburban, 3 = rural): \n");\
	location = atoi(fgets(buffer, BUFSIZ, stdin));

	//Using functions to compute these parameters.
	area = computeArea(length, width);
	perimeter = computePerimeter(length, width);
	diagonal = computeDiagonal(length, width);
	value = computeValue(area, location);

	//Prints the parameters
	printf("The Area is %.1f\n", area);
	printf("The Perimeter is %.1f\n", perimeter);
	printf("The Diagonal is %.1f\n", diagonal);
	printf("The Value is $%.0f\n", value);

	return EXIT_SUCCESS;
}

float computeArea(float length, float width) {
	return (length * width);
}
float computePerimeter(float length, float width) {
	float n = 2 * (length + width);
	return n;
}
float computeDiagonal(float length, float width) {
	float n = sqrt(pow(length, 2) + pow(width, 2));
	return n;
}
float computeValue(float area, int locationType) {
	float value;
	if (locationType == 1) {
		value = area * 1000;
	}
	if (locationType == 2) {
		value = area * 500;
	}
	if (locationType == 3) {
		value = area * 100;
	}
	return value;
}
