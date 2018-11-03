#ifndef STACK_H
#define STACK_H

#include <vector>
#include <algorithm>
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
            : vStack(0) {}

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

    std::reverse(tokens.begin(),tokens.end());

    /*for(int i = 0; i < tokens.size(); i++)
        std::cout << tokens[i] << '\n';*/
}


double evaluate(string input){
    vector<double> result;

    tokenizer(input);


    while (tokens.size() > 0) {


        if (tokens.back() == "+") {
            tokens.pop_back();

            double a = result.back();
            result.pop_back();
            double b = result.back();
            result.pop_back();

            result.push_back(a + b);
        } else if (tokens.back() == "*") {
            tokens.pop_back();

            double a = result.back();
            result.pop_back();
            double b = result.back();
            result.pop_back();

            result.push_back(a * b);
        } else if (tokens.back() == "-") {
            tokens.pop_back();

            double a = result.back();
            result.pop_back();
            double b = result.back();
            result.pop_back();

            result.push_back(b - a);
        } else if (tokens.back() == "/") {
            tokens.pop_back();

            double a = result.back();
            result.pop_back();
            double b = result.back();
            result.pop_back();

            result.push_back(b / a);
        }
        else{
            double a = std::stod(tokens.back());
            result.push_back(a);
            tokens.pop_back();
        }

    }

    return result.back();



/*
        switch (tokens[(tokens.size() - 1)]){
            case "+" :
                tokens.pop_back();
                result.push_back((result.pop_back()) + result.pop_back());
                break;

            case "-" :
                tokens.pop_back();
                double a = result.pop_back();
                double b = result.pop_back();
                result.push_back(b - a);
                break;

            case "*" :
                tokens.pop_back();
                result.push_back((result.pop_back()) * result.pop_back());
                break;

            case "/" :
                tokens.pop_back();
                double a = result.pop_back();
                double b = result.pop_back();
                result.push_back(b / a);
                break;

            default: result.push_back(tokens.pop_back());

        } */



}

// Do not write anything below this line

#endif
