/*
 ============================================================================
 Name        : DAuHtmlSrcList.c
 Author      : Donovan Au
 Version     :
 Copyright   : CS 137
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare
void htmlCount(char htmlDoc[]);
void htmlTags(char htmlDoc[]);
void htmlUrls(char htmlDoc[]);
void htmlFreq(char htmlDoc[]);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	/////////////////////////////////////
	char buffer[BUFSIZ];
	char url[BUFSIZ] = "curl -s ";
	char doc[256000];
	FILE *fp;

	//step 1: print below.
	printf("URL:\n");

	//step 2: get URL
	fgets(buffer, BUFSIZ, stdin);
	buffer[strcspn(buffer, "\n")] = "\0";
	strncat(url, buffer, strlen(buffer) - 1);
	//puts(url); //just to test if curl exists

	//step 3: read document into string in memory (basically make it a whole string.)
	fp = popen(url, "r");
	while (fgets(buffer, BUFSIZ, fp) != NULL) {
		strcat(doc, buffer);
	}
	//printf("%s\n", doc); //for testing

	pclose(fp);
	//
	// NOTE: use doc for our functions
	//

	//step 4: print ready, then while loop
	while (buffer[0] != 'q') {
		printf("Ready\n");
		fgets(buffer, BUFSIZ, stdin);
		switch (buffer[0]) {
		case 'c':
			htmlCount(doc);
			break;
		case 't':
			htmlTags(doc);
			break;
		case 'u':
			htmlUrls(doc);
			break;
		case 'f':
			htmlFreq(doc);
			break;
		case 'q':
			break;
		default:
			printf("Not a command.\n"); //probably don't need, but just because i can.
			break;
		}
	}

	printf("Complete\n");

	return EXIT_SUCCESS;
}
/*use strstr() to find src, go backwards and use isspace() to if src is valid*/
void htmlCount(char htmlDoc[])
{
	int count = 0;
	char *ptr = htmlDoc;

	ptr = strstr(ptr, "src=");
	while (ptr != NULL)
	{
		if (isspace(*(ptr - 1)))
		{
			count++;
		}
		ptr++;
		ptr = strstr(ptr, "src=");
	}

	printf("%d\n", count);
}
/*a bit of previous function, but now go backwards once src is found.*/
void htmlTags(char htmlDoc[]) {
	char *ptr = htmlDoc;
	char *tagPtr1;
	char *tagPtr2;
	char tagName[BUFSIZ];

	ptr = strstr(ptr, "src=");
	while (ptr != NULL)
	{
		if (isspace(*(ptr - 1)))
		{
			tagPtr1 = ptr;
			while (*tagPtr1 != '<')
			{
				tagPtr1--;
			}
			tagPtr2 = tagPtr1;
			while(!isspace(*tagPtr2)){
				tagPtr2++;
			}
			strncpy(tagName, tagPtr1+1, (tagPtr2-tagPtr1)-1);
			printf("%s\n", tagName);
			memset(tagName,0,BUFSIZ); //clear?
		}
		ptr++;
		ptr = strstr(ptr, "src=");
	}
}
/*pretty much copy and paste tags.*/
void htmlUrls(char htmlDoc[]) {
	char *ptr = htmlDoc;
	char *urlPtr1;
	char *urlPtr2;
	char urlLink[BUFSIZ];

	ptr = strstr(ptr, "src=");
	while (ptr != NULL)
	{
		if (isspace(*(ptr - 1)))
		{
			urlPtr1 = ptr;
			while (*urlPtr1 != '\"')
			{
				urlPtr1++;
			}
			urlPtr2 = urlPtr1+1;
			while(*urlPtr2 != '\"'){
				urlPtr2++;
			}
			strncpy(urlLink, urlPtr1+1, (urlPtr2-urlPtr1)-1);
			printf("%s\n", urlLink);
			memset(urlLink,0,BUFSIZ);
		}
		ptr++;
		ptr = strstr(ptr, "src=");
	}
}
void htmlFreq(char htmlDoc[]) {
	printf("Not finished.");
}

