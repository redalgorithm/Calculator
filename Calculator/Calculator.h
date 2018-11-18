// Calculator.h (specification file)
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
#ifndef Calculator_h
#define Calculator_h

#include <iostream>     // I/O
#include <vector>       // Include vector STL class
#include <stack>        // Include stack STL class
#include <map>
#include "Token.h"      // Include header file "Token"
using namespace std;

// PARENMATCH FUNCTIONS
bool parenMatch (vector<Token> expr);


// INFIXTOPOSTFIXTEST FUNCTIONS
// infix to postfix function prototype
void infixToPostfix(vector<Token> &infix, vector<Token> &postfix);

// priority function prototype
int priority(Token & t);    // assumes t.ttype is OPERATOR, OPEN, CLOSE, or END

// printing a Token vector
void printTokenVector(vector<Token> & tvec);


// POSTFIXEVALTEST FUNCTIONS
// postfix evaluate function prototype
double postfixEval(vector<Token> &expr, map<char,double>& mapa);


#endif /* Calculator_h */
