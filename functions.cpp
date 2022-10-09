/********************************************************************************
 * File  :   functions.cpp                                                      *
 * Author: Mohammad Seeam                                                       *
 * Assignment 5: Stacks                                                         *
 * This is a simple application to demonstrate struct and stack in C++.         *
 * This header structure for all cpp and h files.                               *
 * This file, functions.cpp, includes only functions.h                          *
 ********************************************************************************/

#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = (rand() % MAXSTRSIZE) +1;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete[] buffer;
    return;
}

bool isInteger(const std::string& s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}


