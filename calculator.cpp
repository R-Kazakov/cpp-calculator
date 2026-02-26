
#include <string>
#include <cmath>
#include "calculator.h"

using Number=double;
using Sign=std::string;

void Calculator::Set(Number n){
    result_=n;
}

Number Calculator::GetNumber() const{
    return result_;
}

void Calculator::Add(Number n){
    result_+=n;
}
void Calculator::Sub(Number n){
    result_-=n;
}
void Calculator::Div(Number n){
    result_/=n;
}

void Calculator::Mul(Number n){
    result_*=n;
}
void Calculator::Pow(Number n){
    result_=std::pow(result_,n);
}

void Calculator::Save(){
    memory_number_=result_;
    memory_not_empty_=true;
}

void Calculator::Load(){
    result_=memory_number_;
}

bool Calculator::HasMem() const{
    if(memory_not_empty_==true){
        return true;
    }
    return false;
}

std::string Calculator::GetNumberRepr() const{
    std::string result_now=std::to_string(result_);
    return result_now;
}
