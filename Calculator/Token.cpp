// Token.cpp (specification of overloaded ostream operator)
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#include <iostream>
#include "Token.h"
using namespace std;

//------------------------------------------------------
// operator<<
//
// • Overloads ostream operator,
//   prints Token type and associated character/number
//
// Params: passes an ostream and token obj by reference
// I/O: couts a Token
// Return: ostream
//------------------------------------------------------
ostream & operator << (ostream & os, Token & t) {
	os << "<";
	switch (t.getType()) {
		case OPEN:
			os << "OPEN," << t.getChar(); break;
		case CLOSE:
			os << "CLOSE," << t.getChar(); break;
		case OPERATOR:
			os << "OPER," << t.getChar(); break;
		case VARIABLE:
			os << "VARI," << t.getChar(); break;
		case VALUE:
			os << "VALU," << t.getNumber(); break;
		case END:
			os << "END" ; break;
		default: os << "UNKNOWN";
	}
	os << ">";
	return os;
}		
