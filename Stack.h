#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;

// TODO: Your code goes here

class Stack {

private:
    vector<int> vStack;
    vector<char> tokens;
    int count = 0;

public:

    Stack()
            : vStack(0)
    {

    }

    bool empty(){
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    void push(double item){
        vStack.push_back(item);
        count++;

    }

    double pop(){
        double temp = vStack.back();
        vStack.pop_back();
        count--;
        return temp;
    }


};



double evaluate(string input){

}

// Do not write anything below this line

#endif
