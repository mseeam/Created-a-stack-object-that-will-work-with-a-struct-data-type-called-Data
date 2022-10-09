/********************************************************************************
 * File  :   stack.cpp                                                          *
 * Author: Mohammad Seeam                                                       *
 * Assignment 5: Stacks                                                         *
 * This is a simple application to demonstrate struct and stack in C++.         *
 * This header structure for all cpp and h files.                               *
 * This file, stack.cpp, includes stack.h                                       *
 ********************************************************************************/

#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

Stack::Stack(int size) {

    if(size<CHECK_CONSTRUCTOR_PARAMETER){
        size=DEFAULT_CONSTRUCTOR_PARAMETER;
    }

    this->top = -1;
    this->size=size;
    this->stack = new Data*[size];
}

Stack::~Stack() {

    //first delete the elements in the array
    for(int element=top;element>-1; element--){
        delete stack[element];
    }
    
    top=-1;

    delete[] stack;
    stack=NULL;
    size=0;
}

bool Stack::push(int id, string& information){
    
    bool check_push_success=false;

    if(top<size-1 && id>=0 && information!=""){

        Data* data= new Data;
        data->id=id;
        data->information=information;
        stack[++top]=data;

        check_push_success=true;

    }

    return check_push_success;
}


bool Stack::pop(Data *data) {

    bool check_pop_success = false;

    if(isEmpty()){
        data->id=-1;
        data->information="";
    }else{
        data->id=stack[top]->id;
        data->information=stack[top]->information;
        delete stack[top];
        --top;
        check_pop_success=true;

    }
    return check_pop_success;
}

bool Stack::peek(Data *data) {

    bool check_peek_success = false;

    if(isEmpty()){
        data->id=-1;
        data->information="";
    }else{
        data->id=stack[top]->id;
        data->information=stack[top]->information;
        check_peek_success=true;
    }

    return check_peek_success;
}


bool Stack::isEmpty() {
    return top < 0;
}
