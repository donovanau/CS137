/*
 ============================================================================
 Name        : DAuDynamicMemoryICA.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//declare
void bubbleSort(int n[], int size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(void) {
	int iSize;
	int *data;
	int order;

	char buffer[BUFSIZ];
	/*Ask the user for the number of data points to work with
	 (you can assume all data points are of type int ).
	 Saves that number in an integer variable iSize. */
	printf("Input the amount of data points to sort:\n");
	iSize = atoi(fgets(buffer, BUFSIZ, stdin));

	/*Use malloc() to dynamically allocates a block of memory (an array)
	 large enough to fit the exact number of data points.
	 Make sure the allocation was successful by checking malloc()’s
	 return pointer for NULL.*/
	data = (int*) malloc(iSize * sizeof(int));

	if (data == NULL) {
		printf("ERROR: Unable to allocate memory.\n");
		return EXIT_FAILURE;
	}

	/*Use a for loop to fill the array by asking the user
	 to enter the values, 1 at a time (1 per line).*/
	printf("Enter every value in the array:\n");
	for (int i = 0; i < iSize; i++) {
		fgets(buffer, BUFSIZ, stdin);
		data[i] = atoi(buffer);
	}

	/*Ask the user if they want to sort in ascending or descending order.
	 (Note: User can enter 1 for ascending. 2 for descending)*/
	printf("Sort in ascending (1) or descending (2) order?\n");
	order = atoi(fgets(buffer, BUFSIZ, stdin));

	/*Use the BubbleSort() function implemented above to sort accordingly.*/
	switch (order) {
	case 1:
		bubbleSort(data, iSize, ascending);
		break;
	case 2:
		bubbleSort(data, iSize, descending);
		break;
	}

	/*Display the sorted list.*/
	for (int i = 0; i < iSize; i++) {
		printf("%d\t", data[i]);
	}

	free(data);

	return EXIT_SUCCESS;
}

/* bubble sort takes in a compare function pointer to call the correct function depending
 on sort type */
void bubbleSort(int n[], int size, int (*compare)(int a, int b)) {
	int pass, i, temp;
	for (pass = 1; pass < size; pass++) {
		for (i = 0; i < size - 1; i++) {
			if ((*compare)(n[i], n[i + 1])) { //If not in order, swap
				temp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = temp;
			}
		}
	}
}

/* returns 1 if not in ascending order */
int ascending(int a, int b) {
	return (a > b) ? 1 : 0;
}

/* returns 1 if not in descending order */
int descending(int a, int b) {
	return (a < b) ? 1 : 0;
}
