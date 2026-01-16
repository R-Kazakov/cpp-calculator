#include <iostream>
#include <cmath>
#include "calculator.h"

using Number=double;
using Sign=std::string;

bool ReadNumber(Number& result){
    bool read_ok = true;
    Number new_num;
    if(!(std::cin>>new_num)) {
        read_ok = false;
        std::cerr<<"Error: Numeric operand expected"<<std::endl;
    } else {
        result=new_num;
    }
    return read_ok;
}

bool ReadSign (Sign& operation){
    bool read_ok = true;
    Sign new_oper;
    std::cin>>new_oper;
    if(!(new_oper=="+" || new_oper=="-" || new_oper=="*" || new_oper=="/" || new_oper=="**" || new_oper==":"||new_oper=="q"||new_oper=="="|| new_oper=="c" || new_oper=="s" || new_oper=="l")){
        read_ok = false;
        std::cerr<<"Error: Unknown token "<<new_oper<<std::endl;
    } else {
        operation=new_oper;
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
                Number next_num=0;
                if(ReadNumber(next_num)==false) {
                    break;
                } else if(operation=="+") {
                    result+=next_num;
                }
                else if(operation=="-") {
                    result-=next_num;
                }
                else if(operation=="*") {
                    result*=next_num;
                }
                else if(operation=="/") {
                    result/=next_num;
                }
                else if(operation=="**") {
                    result=std::pow(result,next_num);
                }
                else if(operation==":") {
                    result=next_num;
                }
            }
        }
    }
    return calculate_ok;
}
