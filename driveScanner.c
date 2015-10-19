/*
* CS4280 Fall 2014 - Project P1
* Author: Loc Nguyen
*
* $Id: driveScanner.c,v 1.4 2014/10/26 17:49:10 lhn7c5 Exp lhn7c5 $
* $Source: /accounts/students/l/lhn7c5/4280/P1/RCS/driveScanner.c,v $
* Last modified:
*       by $Author: lhn7c5 $
*       on $Date: 2014/10/26 17:49:10 $
*
* $Log: driveScanner.c,v $
* Revision 1.4  2014/10/26 17:49:10  lhn7c5
* Final submission.
*
* Revision 1.3  2014/10/26 10:09:00  lhn7c5
* Done keywords, identifiers, and numbers.
*
* Revision 1.2  2014/10/24 03:23:40  lhn7c5
* Check for invalid characters and max word length
* 	- exclude extra characters, such as delimiters and operators (., :, +, {, etc.)
* 	- exclude comment line starting with //
*
* Revision 1.1  2014/10/23 20:40:08  lhn7c5
* Initial revision
*
*/

#include <stdio.h>
#include <ctype.h>

#include "token.h"
#include "scanner.h"

int main(int argc, char *argv[])
{
	FILE *filePtr;
	/*---------Begin process cmd-line args and Redirection--------*/

	switch (argc) {
		case 1: // No parameters, use stdin
			// printf("NO argument provided\n");
			filePtr = stdin;
			break;

		case 2: // One parameter, use .lan file supplied	
			if ( (filePtr = fopen(strcat(argv[1], ".lan"), "r")) == NULL ) {
				printf("Cannot open input file.\n");
				exit(1);
			}
			break;

		default:
			printf("Syntax: scanner [file] (.lan is implicit)\n");
			exit(0);
	}

	/*---------End process cmd-line args and Redirection----------*/

	/*---------Begin check if file empty-----------*/

	fseek(filePtr, 0, SEEK_END);
	if (ftell(filePtr) == 0) {
		printf("File is empty.\n");
		exit(1);
	} else {
		rewind(filePtr);
	}

	/*---------/End check if file empty-------------*/

	/*---------Begin check for invalid characters and max length-------------*/
	
	char c;
	int numLine = 1;

	int charCount = 0;
	char tempStr[MAX]; // ! Remember: C doesn't do array out-of-bound checking! 
	int i;

	int isValid = 1; // true 
	while ((c = fgetc(filePtr)) != EOF) {
		if (c == '\n')
			numLine++;

		// Exclude comment line starting with '//' and ending with new line
		if (c == '/') {
			if (fgetc(filePtr) == '/') {
				while ((c = fgetc(filePtr)) != '\n') {}
				numLine++;
			}			
		}

		if (isalnum(c)) {
			tempStr[charCount] = c; // array out-of-bound checking not happen here
			charCount++;
			if (charCount > MAX) {
				printf("Word '%s' on line number %d is too long. \n", tempStr, numLine);
				exit(1);	
			}
		} else if (isspace(c) || isExAcceptableChar(c)) { 
			charCount = 0;
		} else {
			printf("Invalid character '%c' at line %d. \n", c, numLine);
			isValid = 0; // false
		}

	}

	if (isValid == 0) { 
		printf("Something wrong with the input file. \n");
		exit(1);
	}

	rewind(filePtr);
	
	/*---------/End check for invalid characters and max length-------------*/

	/*---------Begin Job-------------*/
	// At this time, the file is good. Now let scanner.c do the work
	TokenType tokenType = UNDEF;
	
	// Token token; 
	// token.tokenType = tokenType;
	// token.instance = NULL;
	// token.lineNum = -1;
	// while ((token.tokenType = getTokenType(filePtr, &token)) != EOT) {}
	
	while ((tokenType = getTokenType(filePtr)) != EOT) {}
	
	/*---------/End Job-------------*/

	fclose(filePtr);
	return 0;
}

