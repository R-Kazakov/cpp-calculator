#include <iostream>
#include <cmath>
#include "calculator.h"

using Number=double;
using Sign=std::string;

bool ReadNumber(Number& result){
    bool read_ok = true;
    Number new_number=0;
    if(!(std::cin>>new_number)) {
        read_ok = false;
        std::cerr<<"Error: Numeric operand expected"<<std::endl;
    } else {
        result=new_number;
    }
    return read_ok;
}

bool ReadSign (Sign& operation){
    bool read_ok = true;
    Sign new_operation="";
    std::cin>>new_operation;
    if(!(new_operation=="+" || new_operation=="-" || new_operation=="*" || new_operation=="/" || new_operation=="**" || new_operation==":"||new_operation=="q"||new_operation=="="|| new_operation=="c" || new_operation=="s" || new_operation=="l")){
        read_ok = false;
        std::cerr<<"Error: Unknown token "<<new_operation<<std::endl;
    } else {
        operation=new_operation;
    }
    return read_ok;
}

Sign Save(Number result){
    Sign memory=std::to_string(result);
    return memory;
}

bool Load(Sign memory, Number& result){
    bool load_ok=true;
    if(memory.empty()){
        std::cerr<<"Error: Memory is empty"<<std::endl;
        load_ok=false;
    } else {
        result=std::stod(memory);
    }
    return load_ok;
}

void Print (Number result){
    std::cout<<result<<std::endl;
}

bool RunCalculatorCycle(){
    Number result=0;
    Sign operation="";
    Sign memory="";
    bool calculate_ok=false;
    if (ReadNumber(result)==true){
        while(ReadSign(operation)==true){
            //Выполнение прочитанной операции
            if (operation=="q"){
                calculate_ok=true;
                break;
            }
            else if(operation=="=") {
                Print(result);
            }
            else if(operation=="c"){
                result=0;
            }
            else if(operation=="s"){
                memory=Save(result);
            }
            else if(operation=="l"){
                if (Load(memory,result)==false){
                    break;
                }
            }
            else if(operation=="+" || operation=="-" || operation=="*" || operation=="/" || operation=="**" || operation==":"){
                Number next_number=0;
                if(ReadNumber(next_number)==false) {
                    break;
                } else if(operation=="+") {
                    result+=next_number;
                }
                else if(operation=="-") {
                    result-=next_number;
                }
                else if(operation=="*") {
                    result*=next_number;
                }
                else if(operation=="/") {
                    result/=next_number;
                }
                else if(operation=="**") {
                    result=std::pow(result,next_number);
                }
                else if(operation==":") {
                    result=next_number;
                }
            }
        }
    }
    return calculate_ok;
}
