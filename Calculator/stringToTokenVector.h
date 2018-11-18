// stringToTokenVector.h
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#ifndef STRINGTOTOKENVECTOR_H
#define STRINGTOTOKENVECTOR_H
#include <string>
#include <vector>
#include <cstring>
#include "Token.h"
using namespace std;

// STL VECTOR SPECIFICATION //

vector<Token> stringToTokenVector(string str);
vector<Token> stringToTokenVector(char * cstr);

#endif
