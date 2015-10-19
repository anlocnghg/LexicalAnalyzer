/*
* CS4280 Fall 2014 - Project P1 
* Author: Loc Nguyen
* 
* $Id: scanner.h,v 1.3 2014/10/26 17:49:47 lhn7c5 Exp lhn7c5 $
* $Source: /accounts/students/l/lhn7c5/4280/P1/RCS/scanner.h,v $
* Last modified: 
*       by $Author: lhn7c5 $
*       on $Date: 2014/10/26 17:49:47 $
* 
* $Log: scanner.h,v $
* Revision 1.3  2014/10/26 17:49:47  lhn7c5
* Final submission.
*
* Revision 1.2  2014/10/26 10:08:25  lhn7c5
* Done keywords, identifiers, and numbers.
*
* Revision 1.1  2014/10/23 20:40:47  lhn7c5
* Initial revision
*
*/

#ifndef SCANNER_H 
#define SCANNER_H 

int isExAcceptableChar(char);

int isDelimiter(char);
int isOtherOperators(char);
int isStartRelationalOperator(char);

void printToken(Token *); // func prototype
void splitWords();
void printWords();
void printKeywords();
void printNumbers();
void printIdentifiers();
void printDelimiters();
void printOtherOperators();
void printRelationalOperators();
void printSummary();

#endif


