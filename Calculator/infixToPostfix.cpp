// infixToPostfix.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#include "Calculator.h"

// This was determined functional by a series of tests
/*
int main()
{
    
  // Experiment number 1 (has no parentheses)
  //--------------------------------------------------
  vector<Token> infix;
  
  // a + b * c - d / e % f
  //
  infix.push_back(Token(VALUE,5.0));   // a
  infix.push_back(Token(OPERATOR,'+'));
  infix.push_back(Token(VALUE,6.0));   // b
  infix.push_back(Token(OPERATOR,'*'));
  infix.push_back(Token(VALUE,7.0));   // c
  infix.push_back(Token(OPERATOR,'-'));
  infix.push_back(Token(VALUE,18.0));  // d
  infix.push_back(Token(OPERATOR,'/'));
  infix.push_back(Token(VALUE,3.0));   // e
  infix.push_back(Token(OPERATOR,'%'));
  infix.push_back(Token(VALUE,4.0));   // f

  cout << "Infix expression: ";
  printTokenVector(infix);
  cout << endl;
// (uncomment as appropriate)
 
  vector<Token> postfix;  // create empty postfix vector
  infixToPostfix(infix, postfix);  // call inToPost to fill up postfix vector from infix vector
  // should be a b c * + d e / f % -
  //
  cout << "Postfix expression: ";
  printTokenVector(postfix);
  cout << endl << endl;


  // Experiment number 2 (has parentheses)
  //--------------------------------------------------
  vector<Token> infix2;
  
  // (a + b * c - d) / (e % f)
  //
  infix2.push_back(Token(OPEN));          
  infix2.push_back(Token(VALUE,5.0));   // a
  infix2.push_back(Token(OPERATOR,'+'));
  infix2.push_back(Token(VALUE,6.0));   // b
  infix2.push_back(Token(OPERATOR,'*'));
  infix2.push_back(Token(VALUE,7.0));   // c
  infix2.push_back(Token(OPERATOR,'-'));
  infix2.push_back(Token(VALUE,18.0));  // d
  infix2.push_back(Token(CLOSE));          
  infix2.push_back(Token(OPERATOR,'/'));
  infix2.push_back(Token(OPEN));          
  infix2.push_back(Token(VALUE,3.0));   // e
  infix2.push_back(Token(OPERATOR,'%'));
  infix2.push_back(Token(VALUE,4.0));   // f
  infix2.push_back(Token(CLOSE));          

  cout << "Infix expression: ";
  printTokenVector(infix2);
  cout << endl;
  // (uncomment as appropriate)
  
  vector<Token> postfix2;  // create empty postfix vector
  infixToPostfix(infix2, postfix2);  // call inToPost to fill up postfix vector from infix vector
  
  // should be a b c * + d - e f % / 
  //
  cout << "Postfix expression: ";
  printTokenVector(postfix2);
  cout << endl << endl;
  
  
  return 0;
}
*/

//--------------------------------------------
// printTokenVector (function)
//
// • Prints a vector of Tokens
//
// Params: an expression as vector of Tokens
// I/O: outputs a vector of Tokens
// Return: void (nothing)
//--------------------------------------------
void printTokenVector(vector<Token> & tvec)
{
    //---------------MODIFIED-----------------------
    Token token;
    for (int i=0; i<tvec.size(); i++)
    {
        token = tvec[i];
        if(token.getType() == VALUE)
        {
            cout << token.getNumber() << " ";
        }
        else
            cout << token.getChar() << " ";
    }
    cout << endl;
    //---------------MODIFIED-----------------------
    
	for (int i = 0; i < tvec.size(); i++) {
		cout << tvec[i] << " ";
	}
	cout << endl;
}

//--------------------------------------------
// priority (function)
//
// • Returns priority level of token
//   according to type
//
// Params: a token obj by reference
// I/O: none
// Return: int
//--------------------------------------------
int priority(Token & t) // assumes t.ttype is OPERATOR, OPEN, CLOSE, or END
{
   // add code to return the priority value according to the following table:
   // * / % returns 2
   // + - returns 1
   // OPEN returns 0
   // END returns -1
    int P;
    
   switch(t.getChar())
    {
        case '*':
        case '/':
        case '%': P=2;
            break;
        case '+':
        case '-': P=1;
            break;
    }
    
    if(t.getType()==OPEN)
        P=0;
    else if(t.getType()==END)
        P=-1;
    
    return P;
}

//--------------------------------------------
// infixToPostfix (function)
//
// • Converts infix expression to postfix
//   using Token vectors
//
// Params: an infix Token vector and
//         an empty postfix vector
//         by reference
// I/O: none
// Return: void (nothing)
//--------------------------------------------
void infixToPostfix(vector<Token>& infix, vector<Token>& postfix)
{
    Token token;
    stack<Token> stack;
    postfix.resize(0);
    
    for(int i=0; i<infix.size(); i++)
    {
        token = infix[i];
        
        if(token.getType() == OPEN)
        {
            stack.push(token);
        }
        else if(token.getType() == CLOSE)
        {
            token = stack.top();
            stack.pop();
            while(token.getType() != OPEN)
            {
                postfix.push_back(token);
                token = stack.top();
                stack.pop();
            }
        }
        else if(token.getType() == OPERATOR)
        {
    
            while(!stack.empty() && priority(token) <= priority(stack.top()))
                  {
                      Token top = stack.top();
                      stack.pop();
                      postfix.push_back(top);
                  }
            stack.push(token);
        }
        else
        {
            // the character is an operand and does not belong on the stack
            postfix.push_back(token);
        }
    }
    
    while(!stack.empty())
    {
        token = stack.top();
        stack.pop();
        postfix.push_back(token);
    }
    
    //printTokenVector(postfix);  takes a reference to postfix as param so updated in mem.
}
