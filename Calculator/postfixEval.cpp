// postfixEval.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#include "Calculator.h"

// This was determined functional by a series of tests
/*
int main() {

  vector<Token> postfix;
  
  postfix.push_back(Token(VALUE,4.0));
  postfix.push_back(Token(VALUE,3.0));
  postfix.push_back(Token(VALUE,2.0));
  postfix.push_back(Token(OPERATOR,'*'));
  postfix.push_back(Token(OPERATOR,'+'));
  postfix.push_back(Token(VALUE,18.0));
  postfix.push_back(Token(VALUE,6.0));
  postfix.push_back(Token(OPERATOR,'/'));
  postfix.push_back(Token(OPERATOR,'-'));

  double result = 0.0;
  result = postfixEval(postfix);
  
  cout << "The result of 4 3 2 * + 18 6 / - .... is "
       << result << endl;
       
  vector<Token> postfix2;
  
  postfix2.push_back(Token(VALUE,3.0));
  postfix2.push_back(Token(VALUE,7.0));
  postfix2.push_back(Token(VALUE,2.0));
  postfix2.push_back(Token(OPERATOR,'*'));
  postfix2.push_back(Token(OPERATOR,'+'));
  postfix2.push_back(Token(VALUE,8.0));
  postfix2.push_back(Token(VALUE,16.0));
  postfix2.push_back(Token(OPERATOR,'/'));
  postfix2.push_back(Token(OPERATOR,'-'));

  result = 0.0;
  result = postfixEval(postfix2);
  
  cout << "The result of 3 7 2 * + 8 16 / - .... is "
       << result << endl;
    
  return 0;
}
*/

//--------------------------------------------
// postfixEval (function)
//
// • Evaluates an expression
//   takes in an STL map to evaluate
//   expressions with variables
//
// Params: a Token vector expression and
//         STL map by reference
// I/O: outputs error messages
// Return: double
//--------------------------------------------
double postfixEval(vector<Token> &expr, map<char,double>& mapa)
{
    // allocate a stack of type double (dstack)
    double result;
    stack<double> stack;
    Token token;
    // while not end of vector  // could be a for-loop
    for(int i=0; i<expr.size(); i++)
    {
        token = expr[i];
        
        if(token.getType() == VALUE)
        {
            stack.push(token.getNumber());
            result = token.getNumber();
        }
        else if(token.getType() == OPERATOR)
        {
            if(stack.empty())
            {
                cout << "Stack is empty. Revaluate your vector.\n";
                exit(1);
            }
            else if(stack.size()<2)
            {
                switch(token.getChar())
                {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                        cout << "Not enough values to perform this operation. Revaluate your vector.\n";
                        exit(2);
                        break;
                    //default:
                }
            }
            
            double right, left;
            switch(token.getChar())
            {
                case '+':
                    right = stack.top(); stack.pop();
                    left = stack.top(); stack.pop();
                    result = left + right;
                    break;
                case '-':
                    right = stack.top(); stack.pop();
                    left = stack.top(); stack.pop();
                    result = left - right;
                    break;
                case '*':
                    right = stack.top(); stack.pop();
                    left = stack.top(); stack.pop();
                    result = left * right;
                    break;
                case '/':
                    right = stack.top(); stack.pop();
                    left = stack.top(); stack.pop();
                    if(left != 0 && right == 0)
                    {
                        cout << "Fraction is undefined (for 1/x, when x=0).\n";
                        exit(8);
                    }
                    result = left / right;
                    break;
                case '%':
                    result = left - static_cast<int>(left);
                    result > 0.4 ? left+=1 : left;
                    result = right - static_cast<int>(right);
                    result > 0.4 ? right+=1 : right;
                    result = static_cast<int>(left) % static_cast<int>(right);
                    break;
                default: cout << "Not a valid operator. Revaluate your vector.\n"; exit(4);
            }
            stack.push(result);
        }
        else if(token.getType() == VARIABLE)
        {
            map<char,double>::iterator it;
            it = mapa.find(token.getChar());
            stack.push(it->second);
        }
        else
        {
            cout << "ERROR: Invalid Token! Revaluate your vector.\n";
            exit(4);
        }
    }
    return result;
}
