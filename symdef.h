/*
* CS4280 Fall 2014 - Project P1 
* Author: Loc Nguyen
* 
* $Id: symdef.h,v 1.4 2014/10/26 17:50:09 lhn7c5 Exp lhn7c5 $
* $Source: /accounts/students/l/lhn7c5/4280/P1/RCS/symdef.h,v $
* Last modified: 
*       by $Author: lhn7c5 $
*       on $Date: 2014/10/26 17:50:09 $
* 
* $Log: symdef.h,v $
* Revision 1.4  2014/10/26 17:50:09  lhn7c5
* Final submission.
*
* Revision 1.3  2014/10/26 10:06:37  lhn7c5
* Done keywords, identifiers, and numbers.
*
* Revision 1.2  2014/10/26 09:29:25  lhn7c5
* First set-up with definitions and supporting variables for scanner.
*
*/

#ifndef SYMDEF_H 
#define SYMDEF_H 

char *keywords[15] = {"start", "finish", "then", "if", "repeat", "var", 
	"int", "float", "do",
	"read", "print", "void", "return", "dummy", "program"};	

char *relationalOperators[] = {"==", "<", ">", "=!=", "=>", "=<"};

// char *otherOperators[] = {":", "+", "-", "*", "/", "%"};
char otherOperators[6] = {':', '+', '-', '*', '/', '%'};

// char *delimiters[9] = {".", "(", ")", ",", "{", "}", ";", "[", "]"};
char delimiters[9] = {'.', '(', ')', ',', '{', '}', ';', '[', ']'};

char words[LIMIT][MAX]; // include identifiers, and keywords
int wordi = 0, wordj = 0;
int wordLineNums[LIMIT];

char keys[LIMIT][MAX]; // to store keywords
int keyi = 0;
int keyLineNums[LIMIT];
   
char idens[LIMIT][MAX]; // to store identifiers
int ideni = 0;
int idenLineNums[LIMIT];

char nums[LIMIT][MAX];  // to store numbers
int numi = 0, numj = 0;
int numLineNums[LIMIT];

/*--------------------*/
char delims[LIMIT]; // to store delimiters
int delimi = 0;
int delimLineNums[LIMIT];

char otherOps[LIMIT]; // to store other operators
int otherOpi = 0;
int otherOpLineNums[LIMIT];

char relOps[LIMIT][MAX]; // to store keywords
int relOpi = 0, relOpj = 0;
int relOpLineNums[LIMIT];











#endif


