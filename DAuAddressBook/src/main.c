/*
 ============================================================================
 Name        : main.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : The address book program receives commands from the standard input.
 --------------The commands allow the user to add, edit, and delete contacts, as well as
 --------------load or save contacts from/to a file.  Sorting of contacts is extra credit.
 --------------Each contact has a first name, last name, email address, and phone number.
 ============================================================================
 */

#include "address_book.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	/////////////////////////////////////
	Contact *pHead = NULL;
	Contact *pCur = NULL;
	int index;
	char buffer[BUFSIZ];
	char buffer2[BUFSIZ];

	//for file stuff
	FILE *fp;

	//I. Prints "Ready\n" to the stdout.
	printf("Ready\n");

	//II. While the quit command has not been received:
	while (buffer[0] != 'q') {
		//printf("PRINT TEST\n");
		//A. Receives a command from the standard input
		fgets(buffer, BUFSIZ, stdin);
		switch (buffer[0]) {
		case 'a':
			//1. Add a new contact:
			index = atoi(fgets(buffer, BUFSIZ, stdin)); //first param
			pCur = GetContact(pHead, index - 1);

			fgets(buffer, BUFSIZ, stdin); //second param
			buffer[strlen(buffer) - 1] = '\0'; //get rid of \n

			pCur = InsertContact(&pHead, pCur, buffer);

			break;
		case 'd':
			//2. Delete a contact:
			index = atoi(fgets(buffer, BUFSIZ, stdin)); //first param
			pCur = GetContact(pHead, index);
			pCur = DelContact(&pHead, pCur);
			break;
		case 'g':
			//3. Get a contact:
			index = atoi(fgets(buffer, BUFSIZ, stdin)); //first param
			pCur = GetContact(pHead, index);

			if (pCur)
				printf("%s,%s,%s,%s\n", pCur->lastName, pCur->firstName,
						pCur->email, pCur->phoneNumber);
			break;
		case 'f':
			//4. Get a field:
			index = atoi(fgets(buffer, BUFSIZ, stdin)); //first param
			pCur = GetContact(pHead, index);

			fgets(buffer, BUFSIZ, stdin); //second param (lastName, firstName, email, phoneNumber)
			buffer[strlen(buffer) - 1] = '\0'; //get rid of \n
			FieldContact(pCur, buffer);
			break;
		case 'n':
			//5. Get the number of contacts in the list:
			printf("%d\n", NumberContact(pHead));
			break;
		case 'l':
			index = NumberContact(pHead); //if empty fills up from there

			fgets(buffer, BUFSIZ, stdin); //only param
			buffer[strlen(buffer) - 1] = '\0';
			fp = fopen(buffer, "r"); // we using "mycontacts.csv"

			fgets(buffer, BUFSIZ, fp); //get rid of header

			while (fgets(buffer, BUFSIZ, fp) != NULL) {
				pCur = GetContact(pHead, index - 1);
				buffer[strlen(buffer) - 1] = '\0';

				pCur = InsertContact(&pHead, pCur, buffer);

				index++;
			}

			fclose(fp);
			break;
		case 's':
			//7. Save the contacts to a file:
			pCur = pHead;

			fgets(buffer, BUFSIZ, stdin); //only param
			buffer[strlen(buffer) - 1] = '\0';
			fp = fopen(buffer, "w"); // we using "mycontacts.csv"

			fprintf(fp, "lastName,firstName,email,phoneNumber\n");
			while (pCur) {
				fprintf(fp, "%s,%s,%s,%s\n", pCur->lastName, pCur->firstName,
						pCur->email, pCur->phoneNumber);
				pCur = pCur->pNext;
			}

			fclose(fp);
			break;
		case 'q':
			//8. Quit program:
			printf("Complete\n");
			break;
		case 'e':
			//EC: 9. Edit a contact:
			index = atoi(fgets(buffer, BUFSIZ, stdin)); //first param
			pCur = GetContact(pHead, index);

			fgets(buffer, BUFSIZ, stdin); //second param (lastName, firstName, email, phoneNumber)
			buffer[strlen(buffer) - 1] = '\0'; //get rid of \n

			fgets(buffer2, BUFSIZ, stdin); //third param (replacement)
			buffer2[strlen(buffer2) - 1] = '\0'; //get rid of \n

			pCur = EditContact(pCur, buffer, buffer2);
			break;
		default:
			//printf("Not a command.\n"); //not needed i guess, fails at grading.
			break;
		}
	}

	return EXIT_SUCCESS;
}
