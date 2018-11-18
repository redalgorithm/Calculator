// parenMatch.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#include "Calculator.h"

//--------------------------------------------
// parenMatch
//
// • Checks if parentheses,
//   brackets (supported open-close tokens)
//   match in expression
//
// Params: the expression as vector of Tokens
// I/O: none
// Return: bool
//--------------------------------------------
bool parenMatch (vector<Token> expr)
{
    long n = expr.size();           // Assign size of vector to n.
    
    stack<Token> S;                 // Create a stack of Tokens.
    
    for(int i=0; i<n; i++)
    {
        Token X = expr[i];          // Assign Token element to X temporarily.
        
        if(X.getType() == OPEN)     // Push all OPEN Tokens from the vector of Tokens on the stack.
        {
            S.push(X);
        }
        else if(X.getType() == CLOSE)
        {
            if(S.empty())           // If there is nothing to match the CLOSE symbols with, return false.
            {
                return false;
            }
            
            // If the CLOSE symbol does not match the
            // last OPEN symbol, then
            // out of order (OPEN symbols don't line up correctly).
            //
            switch(S.top().getChar())
            {
                case '(': if(X.getChar()!=')') {return false;}
                    break;
                case '[': if(X.getChar()!=']') {return false;}
                    break;
                case '{': if(X.getChar()!='}') {return false;}
                    break;
            }
            
            S.pop();                // Pop the matched OPEN Token from the stack.
        }
        
        // continue looping until end of vector
    }
    
    // If the stack is still empty, then
    // all OPEN symbols were evenly
    // matched and popped off and parenMatch is true.
    // Otherwise, parenMatch is false.
    //
    if(S.empty())
    {
        return true;
    }
    else
        return false;
}

// This was determined functional by a series of tests
/*
int main()
{
    // EXPRESSION 1 (assign and print expression 1)
    //-----------------------------------------------
    //
	vector<Token> expr1;                                // Create a vector of Tokens.
	expr1.push_back(Token(OPEN,'('));
	expr1.push_back(Token(CLOSE,')'));
	expr1.push_back(Token(END));
    // (String Perspective): "()"
	
	cout << "Expression 1: ";
	for (int i = 0 ; i < expr1.size(); i++)
    {
		cout << expr1[i] << " ";
	}
	cout << endl;
	
	// Call parenMatch(expr1) and report the result.
    //
    if(parenMatch(expr1))
    {
        cout << "SYMBOLS MATCH" << endl;
    }
    else
    {
        cout << "SYMBOLS DO NOT MATCH" << endl;
    }
    //
    //-----------------------------------------------
    //-----------------------------------------------

    
    // EXPRESSION 2 (assign and print expression 2)
    //-----------------------------------------------
    //
	vector<Token> expr2;                                // Create another vector of Tokens.
	expr2.push_back(Token(OPEN,'('));
	expr2.push_back(Token(OPEN,'('));
	expr2.push_back(Token(OPEN,'('));
	expr2.push_back(Token(OPEN,'('));
	expr2.push_back(Token(OPEN,'('));
	expr2.push_back(Token(CLOSE,')'));
	expr2.push_back(Token(CLOSE,')'));
	expr2.push_back(Token(CLOSE,')'));
	expr2.push_back(Token(END));
	// (String Perspective): "((((()))"
    
	cout << "Expression 2: ";
	for (int i = 0 ; i < expr2.size(); i++)
    {
		cout << expr2[i] << " ";
	}
	cout << endl;
    
    // Call parenMatch(expr2) and report the result.
    //
    if(parenMatch(expr2))
    {
        cout << "SYMBOLS MATCH" << endl;
    }
    else
    {
        cout << "SYMBOLS DO NOT MATCH" << endl;
    }
    //
    //-----------------------------------------------
    //-----------------------------------------------
    
    // EXPRESSION 3 (assign and print expression 3)
    //-----------------------------------------------
    //
	vector<Token> expr3;                                // Create a third vector of Tokens.
	expr3.push_back(Token(OPEN,'('));
	expr3.push_back(Token(CLOSE,')'));
	expr3.push_back(Token(OPEN,'('));
	expr3.push_back(Token(OPEN,'('));
	expr3.push_back(Token(CLOSE,')'));
	expr3.push_back(Token(CLOSE,')'));
	expr3.push_back(Token(CLOSE,')'));
	expr3.push_back(Token(END));
    // (String Perspective): "()(()))"
    
	cout << "Expression 3: ";
	for (int i = 0 ; i < expr3.size(); i++) {
		cout << expr3[i] << " ";
	}
	cout << endl;
    
    // Call parenMatch(expr3) and report the result.
    //
    if(parenMatch(expr3))
    {
        cout << "SYMBOLS MATCH" << endl;
    }
    else
    {
        cout << "SYMBOLS DO NOT MATCH" << endl;
    }
    //
    //-----------------------------------------------
    //-----------------------------------------------
    
    // EXPRESSION 4 (assign and print expression 4)
    //-----------------------------------------------
    //
	vector<Token> expr4;                                // Create a fourth vector of Tokens.
	expr4.push_back(Token(OPEN,'('));
	expr4.push_back(Token(VARIABLE,'A'));
	expr4.push_back(Token(CLOSE,')'));
	expr4.push_back(Token(OPEN,'('));
	expr4.push_back(Token(OPEN,'['));
	expr4.push_back(Token(VARIABLE,'A'));
	expr4.push_back(Token(OPERATOR,'+'));
	expr4.push_back(Token(VARIABLE,'B'));
	expr4.push_back(Token(CLOSE,']'));
	expr4.push_back(Token(OPERATOR,'*'));
	expr4.push_back(Token(OPEN,'{'));
	expr4.push_back(Token(VARIABLE,'A'));
	expr4.push_back(Token(OPERATOR,'-'));
	expr4.push_back(Token(VARIABLE,'B'));
	expr4.push_back(Token(CLOSE,'}'));
	expr4.push_back(Token(CLOSE,')'));
	expr4.push_back(Token(END));
	// (String Perspective): "(A)([A+B]*{A-B})"
    
	cout << "Expression 4: ";
	for (int i = 0 ; i < expr4.size(); i++) {
		cout << expr4[i] << " ";
	}
	cout << endl;

    // Call parenMatch(expr4) and report the result.
    //
    if(parenMatch(expr4))
    {
        cout << "SYMBOLS MATCH" << endl;
    }
    else
    {
        cout << "SYMBOLS DO NOT MATCH" << endl;
    }
    //
    //-----------------------------------------------
    //-----------------------------------------------
    
    // EXPRESSION 5 (assign and print expression 5)
    //-----------------------------------------------
    //
	vector<Token> expr5;                                // Create a fifth vector of Tokens.
	expr5.push_back(Token(OPEN,'('));
	expr5.push_back(Token(OPEN,'['));
	expr5.push_back(Token(OPEN,'{'));
	expr5.push_back(Token(CLOSE,')'));
	expr5.push_back(Token(CLOSE,']'));
	expr5.push_back(Token(CLOSE,'}'));
	expr5.push_back(Token(END));
	// (String Perspective): "([{)]}"
    
	cout << "Expression 5: ";
	for (int i = 0 ; i < expr5.size(); i++) {
		cout << expr5[i] << " ";
	}
	cout << endl;
    
    // Call parenMatch(expr5) and report the result.
    //
    if(parenMatch(expr5))
    {
        cout << "SYMBOLS MATCH" << endl;
    }
    else
    {
        cout << "SYMBOLS DO NOT MATCH" << endl;
    }
    //
    //-----------------------------------------------
    //-----------------------------------------------
	
	
	return 0;
}
*/
