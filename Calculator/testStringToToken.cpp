// testStringToToken.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
/*
    This program utilizes OOP and several
    STL containers to operate as a basic calculator
    in which the user can enter and evaluate expressions
*/

/*
 ___________________________________
 Test Run:
 ___________________________________
 print A
 output:  A is undefined
 A = 5
 print A
 output:  5
 B = A + 7
 
 print B
 output: 12
 C = 3
 X = 2
 D = (A * X + B) / ( C * X - B)
 
 print D
 output: -3.666667
 clear
 print D
 output:  D is undefined
 quit
 ____________________________________
*/


#include <iostream>
#include <string>
#include <map>
#include "Token.h"
#include "stringToTokenVector.h"
#include "Calculator.h"
using namespace std;

const void menu();
void assign(map<char,double>&);
void print(map<char,double>&);

int main()
{
    map<char,double> mapa;
    char choice;
    do
    {
        menu();
        cin >> choice;
        cout << endl;
    
        switch(choice)
        {
            case 'a':
            case 'A':   assign(mapa);
            break;
            case 'b':
            case 'B':   print(mapa);
            break;
            case 'c':
            case 'C':   mapa.clear(); cout << "All variables were successfully cleared." << endl;
            break;
            case 'd':
            case 'D':   cout << "Turning calculator off.\n";
            break;      //exit(0)/return 0
            default:    cout << "Invalid.\nTurning calculator off.\n";
            exit(4);    // $ invalidity [circumstance: ""]
        }
    }while(toupper(choice)!='D');
    
    return 0;
}

const void menu()
{
    cout << "_______________________________________________\n";
    cout << "MENU\n";
    cout << "_______________________________________________\n";
    cout << "what would you like to do with this expression?\n";
    cout << "-----------------------------------------------\n";
    cout << "a) Assign to a var\n";
    cout << "b) Print var value\n";
    cout << "c) Clear\n";
    cout << "d) Quit\n";
    cout << "_______________________________________________\n";
    cout << "Make a choice: ";
}

void assign(map<char,double>& mapa)
{
    string str = "";
    char ch;
    
    // ASSIGN A VALUE/EXPR TO VARIABLE
    // variable name
    do
    {
        cout << "Variable Name: ";
        cin >> ch;
        if(!isalpha(ch))
            cout << "ATTENTION: Variable must be alphabetic. Try again.\n";
    }while(!isalpha(ch));
    
    // variable assignment
    cout << ch << " = ";
    cin.ignore();
    getline(cin,str);
    
    // analyze the expression (string)
    for(int i = 0; i<str.size(); i++)
    {
        //Find a variable
        //Otherwise, exit if not found.
        if(isalpha(str[i]))
        {
            map<char,double>:: iterator it;
            it = mapa.find(str[i]);
            if(it == mapa.end())
            {
                // if the variable is the same as the assignee, assume a is 0 (ex: a = a + 1)
                // (not completely necessary but convenient)
                if(str[i] == ch)
                {
                    // automatically assign the variable a value of 0 (store in map of vars)
                    mapa[ch] = 0;
                    break;
                }
                
                cout << "One or more variables in this expression are undefined.\n";
                
                exit(8);   // * special circumstance ["variable impractical"]
            }
        }
    }
    
    vector<Token> infix,postfix;
    infix = stringToTokenVector(str);   // updated to allow isalpha rather than being restricted to all caps

    if(!parenMatch(infix))
    {
        cout << "SYMBOLS DO NOT MATCH" << endl;
        exit(90);  // () match issue [optional explanation: ""]
    }
    infixToPostfix(infix,postfix);
    double result = postfixEval(postfix, mapa);
    infix.clear();
    postfix.clear();
    
    mapa[ch] = result;      // insert (pair<char,double>(ch,result))  KEY: ch   VALUE: result
    ///////////////////////////////
    // SUCCESS:
    // NOW STORED IN MAP
    ///////////////////////////////
}

void print(map<char,double>& mapa)
{
    char ch;
    map<char,double>::iterator it;

    cout << "Variable Name: ";
    cin >> ch;
    if(!isalpha(ch))
        cout << "ATTENTION: Variable must be alphabetic. Try again.\n";
    else
    {
        it = mapa.find(ch);
        if(it==mapa.end())
        {
            cout << ch << " is undefined.\n";
        }
        else
            cout << ch << " = " << it->second << endl;
    }
}

