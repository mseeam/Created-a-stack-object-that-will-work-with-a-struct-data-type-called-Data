/********************************************************************************
 * File  :   stack.h                                                            *
 * Author: Mohammad Seeam                                                       *
 * Assignment 5: Stacks                                                         *
 * This is a simple application to demonstrate struct and stack in C++.         *
 * This header structure for all cpp and h files.                               *
 * This file, stack.h, includes only data.h                                     *
 *******************************************************************************/

#ifndef STACK_H
#define STACK_H

#include "data.h"

class Stack {

public:

    Stack(int); //constractor
    ~Stack();   //destractor

    //Declaring all the function
    bool push(int,string&);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
    
private:

    int top;
    int size;
    Data** stack;

};

#endif //STACK_H
