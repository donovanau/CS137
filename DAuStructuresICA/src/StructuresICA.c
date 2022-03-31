/*
 ============================================================================
 Name        : StructuresICA.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : In Class Assignment for Structures
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum Gender {
	MALE, FEMALE
};
char *gender[2] = { "male", "female" };

typedef struct {
	char name[BUFSIZ];
	int age;
	int height[2];
	float weight;
	int sex;
	int heartRate;
	int bloodPressure[2]; //two values?
	char doctorNotes[BUFSIZ];
} Patient;

int main(void) {
	Patient John;
	strncpy(John.name, "John Doe", strlen("John Doe"));
	John.age = 48;
	John.height[0] = 5;
	John.height[1] = 10;
	John.weight = 178.2;
	John.sex = MALE;
	John.heartRate = 60;
	John.bloodPressure[0] = 120; //would be separated by a slash
	John.bloodPressure[1] = 80;
	strncpy(John.doctorNotes, "Note: DO NOT use an initialization list, assign the member values 1 at a time.",
			strlen("Note: DO NOT use an initialization list, assign the member values 1 at a time."));
	//The notes are word for word on the ICA :)

	printf("The patient is %s, they are of age %d.\n", John.name, John.age);
return EXIT_SUCCESS;
}
