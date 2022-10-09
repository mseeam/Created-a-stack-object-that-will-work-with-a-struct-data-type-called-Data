/********************************************************************************
 * File  :   main.cpp                                                           *
 * Author: Mohammad Seeam                                                       *
 * Assignment 5: Stacks                                                         *
 * This is a simple application to demonstrate struct and stack in C++.         *
 * This header structure for all cpp and h files.                               *
 * This file, main.cpp, includes only main.h                                    *
 *******************************************************************************/

#include "main.h"

int main(int argc, char** argv) {

    srand(time(NULL));

    int size;
    if(argc==1){
        std::cout << "usage: ./a.out <size>" <<std::endl;
    }else if(argc==2){
        if (isInteger(argv[1])){
            size = atoi(argv[1]);
            if(size<1){
                std::cout << "Argument for stack size must be greater than 0" <<std::endl;
            }else{
                // create stack object stack
                Stack stack(size);

                int value;

                /************************************************
                ******* EMPTY TESTS *****************************
                ************************************************/

                std::cout << "Beginning tests..." << std::endl << std::endl << "Testing empty operations." << std::endl;
                std::cout << "=====================================================" << std::endl;

                if (stack.isEmpty()) {
                    std::cout << "The stack is empty" << std::endl;
                } else {
                    std::cout << "The stack is NOT empty" << std::endl;
                }

                Data *data= new Data;
                if(stack.peek(data)){
                        std::cout<<"Peeked id : "<<data->id<< " and information : " << data->information <<std::endl;
                } else {
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                
                if(stack.pop(data)){
                    std::cout<<"pop id : "<<data->id<< " and information : " << data->information <<std::endl;
                } else {
                    std::cout << "pop underflow error: stack is empty" << std::endl;
                }
                
                std::cout << std::endl;

                /************************************************
                ******** FILLING AND FULL TESTS *****************
                ************************************************/

                std::cout << "Testing full operations." << std::endl;
                std::cout << "=====================================================" << std::endl;


                // testing filling the stack and overflow
                std::cout << "Filling stack..." << std::endl;
                for (int i = 0; i < MAXSTRSIZE*MULTIPLIER; i++) {


                    std::string strtemp;
                    for(int i=0; i<20; i++){
                        rand_string(&strtemp);
                    }

                    value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number

                    if (stack.push(value,strtemp)) {
                        std::cout<<"Pushed id : "<<value<< " and information : " << strtemp <<std::endl;

                    } else {
                        std::cout << "overflow error: " << value << " and "<< strtemp<<" not pushed" << std::endl;
                    }
                }
                std::cout << std::endl;

                if (stack.isEmpty()) {
                    std::cout << "stack is empty" << std::endl;
                } else {
                    std::cout << "stack is NOT empty" << std::endl;
                }
                std::cout << std::endl;

                if(stack.peek(data)==true){
                    std::cout<<"Peeked id : "<<data->id<< " and information : "<<data->information  <<std::endl;
                } else {
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                if(stack.pop(data)){
                    std::cout<<"pop id : "<<data->id<< " and information : " << data->information <<std::endl;
                } else {
                    std::cout << "pop underflow error: stack is empty" << std::endl;
                }
                std::cout << std::endl;


                /************************************************
                ******** EMPTYING AND EMPTY TESTS ***************
                ************************************************/

                std::cout << "Testing peek and pop, and emptying stack..." << std::endl;
                std::cout << "=====================================================" << std::endl;

                // testing popping and peeking whole stack
                for (int i = 0; i < MULTIPLIER*MAXSTRSIZE; i++) {
                    if(stack.peek(data)){
                        std::cout<<"Peeked id : "<<data->id<< " and information : " << data->information <<std::endl;
                    } else {
                        std::cout << "peek underflow error: stack is empty" << std::endl;
                    }

                    if(stack.pop(data)){
                        std::cout<<"pop id : "<<data->id<< " and information : " << data->information <<std::endl;
                    } else {
                        std::cout << "pop underflow error: stack is empty" << std::endl;
                    }
                }
                std::cout << std::endl;


                if (stack.isEmpty()) {
                    std::cout << "stack is empty" << std::endl;
                } else {
                    std::cout << "stack is NOT empty" << std::endl;
                }

                if(stack.peek(data)==true){
                    std::cout<<"Peeked id : "<<data->id<< " and information : " << data->information << std::endl;
                } else {
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                if(stack.pop(data)){
                    std::cout<<"pop id : "<<data->id<< " and information : " << data->information <<std::endl;
                }else {
                    std::cout << "pop underflow error: stack is empty" << std::endl;
                }
                std::cout << std::endl;

                /************************************************
                ******** MID-STACK TESTS ************************
                ************************************************/

                std::cout << "Filling stack halfway and testing the middle of the stack..." << std::endl;
                std::cout << "============================================================" << std::endl;
                // filling the stack half way to test the middle of the stack
                for (int i = 0; i< int(MAXSTRSIZE / 2); i++) {
                    // using positive and negative "big" numbers
                    std::string strtemp;
                    for(int i=0; i<20; i++){
                        rand_string(&strtemp);
                    }
                    value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                    if (stack.push(value,strtemp)) {
                        std::cout<<"Pushed id : "<<value<< " and information : " << strtemp <<std::endl;

                    } else {
                        std::cout << "overflow error: " << value << " and "<< strtemp<<" not pushed" << std::endl;
                    }
                }
                for (int i = 0; i<MAXSTRSIZE*NARROW; i++) {
                    if (stack.isEmpty()) {
                        std::cout << "stack is empty" << std::endl;
                    } else {
                        std::cout << "stack is NOT empty" << std::endl;
                    }
                    std::cout << std::endl;

                    // testing peek() and pop() on empty stack
                    if(stack.peek(data)){
                        std::cout<<"Peeked id : "<<data->id<< " and information : " << data->information <<std::endl;
                    } else {
                        std::cout << "peek underflow error: stack is empty" << std::endl;
                    }

                    if(stack.pop(data)){
                        std::cout<<"pop id : "<<data->id<< " and information : " << data->information <<std::endl;
                    }else {
                        std::cout << "pop underflow error: stack is empty" << std::endl;
                    }

                    value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);  
                    std::string strtemp;
                    for(int i=0; i<20; i++){
                        rand_string(&strtemp);
                    }
                    if (stack.push(value,strtemp)) {
                        std::cout<<"Pushed id : "<<value<< " and information : " << strtemp <<std::endl;
                    } else {
                        std::cout << "overflow error: " << value << " and "<< strtemp<<" not pushed" << std::endl;
                    }
                }
                std::cout << std::endl;


                /************************************************
                ******** RANDOM TESTS ***************************
                ************************************************/
                std::cout << "Random testing..." << std::endl;
                std::cout << "============================================================" << std::endl;

                while(!stack.isEmpty()){
                    stack.pop(data);
                }
                    for (int i = 0; i< int(MAXSTRSIZE / 2); i++) {
                    value = rand() % MAX_INT + 1;
                    std::string strtemp;
                    for(int i=0; i<20; i++){
                        rand_string(&strtemp);
                    }
                    if (stack.push(value,strtemp)) {
                        std::cout<<"Pushed id : "<<value<< " and information : " << strtemp <<std::endl;
                    } else {
                        std::cout << "overflow error: " << value << " and "<< strtemp<<" not pushed" << std::endl;
                    }
                }

                int choice = rand() % CHOICES + 1;
                for (int i = 0; i < MAXSTRSIZE*RANDOM_MULTIPLIER; i++) {
                   std::string strtemp;
                    for(int i=0; i<20; i++){
                        rand_string(&strtemp);
                    }
                    switch (choice) {
                        case 1:
                            // push
                            value = (rand() % MAX_INT) + 1;
                            if (stack.push(value,strtemp)) {
                                std::cout<<"Pushed id : "<<value<< " and information : " << strtemp <<std::endl;
                            } else {
                                std::cout << "overflow error: " << value << " and "<< strtemp<<" not pushed" << std::endl;
                            }
                            break;
                        case 2:
                            // pop
                            if(stack.pop(data)){
                                std::cout<<"pop id : "<<data->id<< " and information : " << data->information <<std::endl;
                            }else {
                                std::cout << "pop underflow error: stack is empty" << std::endl;
                            }
                            break;
                        case 3:
                            // peek
                            if(stack.peek(data)){
                                std::cout<<"Peeked id : "<<data->id<< " and information : " << data->information <<std::endl;
                            } else {
                                std::cout << "peek underflow error: stack is empty" << std::endl;
                            }
                            break;
                        case 4:
                            // isempty
                            if (stack.isEmpty()) {
                                std::cout << "stack is empty" << std::endl;
                            } else {
                                std::cout << "stack is NOT empty" << std::endl;
                            }
                            break;
                    }

                    choice = rand() % CHOICES + 1;
                }

                stack.~Stack();

                std:: cout << std::endl;
                std:: cout << "=====================================================" << std::endl;
                std::cout << "Testing complete." << std::endl;
            }
        }else{
            std::cout << "Argument for stack size must be an integer " <<std::endl;
        }
    }

   return 0;

}