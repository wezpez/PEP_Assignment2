#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
//#include <bits/stdc++.h>

using std::vector;
using std::string;

// TODO: Your code goes here

class Stack {

private:
    vector<int> vStack;
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

vector<string> tokens;

void tokenizer(string input){

    std::stringstream check1(input);

    string temp;

    while(getline(check1, temp, ' '))
    {
        tokens.push_back(temp);
    }

    for(int i = 0; i < tokens.size(); i++)
        std::cout << tokens[i] << '\n';
}


double evaluate(string input){
    tokenizer("3.0 4.0 +");
    return 5;
}

// Do not write anything below this line

#endif
