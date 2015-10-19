/*
* CS4280 Fall 2014 - Project P1
* Author: Loc Nguyen
*
* $Id: token.h,v 1.2 2014/10/26 17:50:30 lhn7c5 Exp lhn7c5 $
* $Source: /accounts/students/l/lhn7c5/4280/P1/RCS/token.h,v $
* Last modified:
*       by $Author: lhn7c5 $
*       on $Date: 2014/10/26 17:50:30 $
*
* $Log: token.h,v $
* Revision 1.2  2014/10/26 17:50:30  lhn7c5
* Final submission.
*
* Revision 1.1  2014/10/23 20:40:25  lhn7c5
* Initial revision
*
*/

#ifndef TOKEN_H 
#define TOKEN_H 

#define MAX 8 // max length of each word string
#define LIMIT 200 // max number of word strings in an input file

typedef enum {
	IDENTIFIER,
	KEYWORD,
	NUMBER,
	REL_OP, 	// such as ==  <  >  =!=    =>  =<
	OP,			// such as = :  +  -  *  / %
	DELIM,		// such as . (  ) , { } ; [ ] 

	UNDEF,		// undefined
	EOT 		// end of token
/*
	REL_OP_EQUAL, // ==
	REL_OP_GREATER, // >
	REL_OP_LESS_THAN, // <
	REL_OP_NOT_EQUAL, // =!=
	REL_OP_NOT_GREATER, // =<
	REL_OP_NOT_LESS_THAN, // =>

	OP_ASSIGN, // =
	OP_COLON, // :
	OP_DIV, // /
	OP_MUL, // *
	OP_ADD, // +
	OP_SUBTRACT, // -
	OP_REMAINDER, // %

	DELIM_DOT, // .
	DELIM_LEFT_PARRENTHESE, // (
	DELIM_RIGHT_PARRENTHESE, // )
	DELIM_COMMA, // ,
	DELIM_LEFT_BRACE, // {
	DELIM_RIHGT_BRACE, // }
	DELIM_LEFT_BRACKET, // [
	DELIM_RIGHT_BRACKET, // ]
	DELIM_SEMICOLON, // ;
*/

} TokenType;

typedef struct {
	TokenType tokenType;
	char *instance;
	int lineNum;

} Token;



#endif
