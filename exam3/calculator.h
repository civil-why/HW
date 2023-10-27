#ifndef _calculator_h_
#define _calculator_h_

#include<iostream>
#include<string>
#include<sstream>
#include"seqstack.h"
#include<math.h>

using namespace std;

class Calculator
{
private:
    SeqStack<double> s;
    void AddOperand(double value);
    bool get2Operands(double&,double&);
    void DoOperator(char op);
public:
    Calculator(int sz=50):s(sz){};
    ~Calculator(){};

    void Run(stringstream&);
    void Clear();
};

#endif