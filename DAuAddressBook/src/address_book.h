/*
 * address_book.h
 *
 *  Created on: Nov 26, 2021
 *      Author: dau
 */

#ifndef ADDRESS_BOOK_H_
#define ADDRESS_BOOK_H_

/*****************************************************************
 INCLUDED FILES
 *****************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************
 STRUCTURE DECLARATIONS
 ******************************************************************/
typedef struct contact Contact;
typedef struct contact* pContact;
struct contact {
	//We need last name, first name, email, and phone number.
	char lastName[128];
	char firstName[128];
	char email[128];
	char phoneNumber[128];
	Contact *pPrev;
	Contact *pNext;
};

/*****************************************************************
 FUNCTION DECLARATIONS
 ******************************************************************/
/* DONE
 * */
Contact *CreateContact(char *fields);

/* DONE
 * */
Contact *InsertContact(pContact * ppFirst, Contact *pPrev, char *fields);

/* DONE
 * */
Contact *DelContact(pContact * ppFirst, Contact *pContact);

/* DONE
 * */
Contact *GetContact(Contact *pContact, int index);

/* DONE
 * */
void FieldContact(Contact *pContact, char *field);

/* DONE
 * */
int NumberContact(Contact *pContact);

Contact* EditContact(Contact *pContact, char *fieldName, char *field);

#endif /* ADDRESS_BOOK_H_ */
