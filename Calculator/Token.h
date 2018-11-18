// Token.h
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

// forward declaration of class for ostream operator overloading
class Token;
ostream & operator << (ostream & os, Token & t);

enum TokenType { OPEN, CLOSE, OPERATOR, VARIABLE, VALUE, END };

//-------------------------------------------
// Token (class)
//
// classic token class
// represents one of 6 different token types
// for calculator expression handling
//
// Private members: yes
// Protected members: no
// Public members: yes
//-------------------------------------------
class Token {

public:
	Token (TokenType t, char c) : ttype(t), ch(c) { }
	Token (TokenType t, double d) : ttype(t), number(d) { }
	Token (TokenType t) : ttype(t) { }
	Token () : ttype (END), ch('?'), number(-99999999) { }
	
	TokenType getType() {return ttype;}
	char getChar() {return ch;}
	double getNumber() {return number;}
	
private:
	TokenType ttype;
	char ch;
	double number;
};



#endif // TOKEN_H
