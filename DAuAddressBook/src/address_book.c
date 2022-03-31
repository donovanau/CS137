#include "address_book.h"

Contact* CreateContact(char *pFields) {
	Contact *pContactNewContact = (Contact*) malloc(sizeof(Contact));
	char sep[] = ",";
	char *ptr = strtok(pFields, sep);

	if (pContactNewContact) {
		strcpy(pContactNewContact->lastName, ptr);
		ptr = strtok(NULL, sep);
		strcpy(pContactNewContact->firstName, ptr);
		ptr = strtok(NULL, sep);
		strcpy(pContactNewContact->email, ptr);
		ptr = strtok(NULL, sep);
		strcpy(pContactNewContact->phoneNumber, ptr);

		pContactNewContact->pPrev = NULL;
		pContactNewContact->pNext = NULL;
	}
	return pContactNewContact;
}

Contact* InsertContact(Contact **ppFirst, Contact *pPrev, char *pFields) {
	Contact *pContactNew = CreateContact(pFields);

	if (pPrev) //not first in list
	{
		pContactNew->pPrev = pPrev;
		pContactNew->pNext = pPrev->pNext;
		pPrev->pNext = pContactNew;

		if (pContactNew->pNext) //next contact exists
			pContactNew->pNext->pPrev = pContactNew;

	} else { //first in list
		pContactNew->pPrev = NULL;
		pContactNew->pNext = *ppFirst;
		if ((*ppFirst)) { //list is not empty
			(*ppFirst)->pPrev = pContactNew;
		}
		*ppFirst = pContactNew;
	}

	return (pContactNew);
}

Contact* GetContact(Contact *pContact, int index) {
	/* move through list until at index */
	//if index == 0 return pcontact
	//index == 1 returns whatever is at index of linkedlist
	int count = 0;

	while (pContact) {
		if (count == index)
			break;

		pContact = pContact->pNext;
		count++;
	}

	return pContact;
}

void FieldContact(Contact *pContact, char *field) {
	if (pContact) {
		if (strcmp(field, "lastName") == 0)
			printf("%s\n", pContact->lastName);

		if (strcmp(field, "firstName") == 0)
			printf("%s\n", pContact->firstName);

		if (strcmp(field, "email") == 0)
			printf("%s\n", pContact->email);

		if (strcmp(field, "phoneNumber") == 0)
			printf("%s\n", pContact->phoneNumber);
	}
}

Contact* DelContact(pContact *ppFirst, Contact *pContact) {
	Contact *pContactReturn;

	if (pContact == NULL)
		return NULL;

	if (pContact == (*ppFirst)) //deleting top contact
			{
		if (pContact->pNext) //not only contact
		{
			pContactReturn = pContact->pNext;
			(*ppFirst) = pContactReturn;
			pContactReturn->pPrev = NULL;
		} else //single contact
		{
			pContactReturn = NULL;
			(*ppFirst) = NULL;
		}
	} else //not deleting top contact
	{
		if (pContact->pNext) //not last contact
		{
			pContactReturn = pContact->pNext;
			pContactReturn->pPrev = pContact->pPrev;
			pContact->pPrev->pNext = pContactReturn;
		} else // delete last contact
		{
			pContactReturn = pContact->pPrev;
			pContactReturn->pNext = NULL;
		}
	}

	free(pContact);

	return (pContactReturn);
}

int NumberContact(Contact *pContact) {
	int count = 0;
	while (pContact) {
		pContact = pContact->pNext;
		count++;
	}
	//printf("%d\n", count);
	return count;
}

Contact* EditContact(Contact *pContact, char *fieldName, char *field) {
	if (pContact) {
		if (strcmp(fieldName, "lastName") == 0){
			strcpy(pContact->lastName, field);
		}

		if (strcmp(fieldName, "firstName") == 0){
			strcpy(pContact->firstName, field);
		}

		if (strcmp(fieldName, "email") == 0){
			strcpy(pContact->email, field);
		}

		if (strcmp(fieldName, "phoneNumber") == 0){
			strcpy(pContact->phoneNumber, field);
		}
	}
	return pContact;
}
