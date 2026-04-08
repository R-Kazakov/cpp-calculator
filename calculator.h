#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

// Реализация шаблонного калькулятора.
template <typename Number>
class Calculator{
public:
    Calculator(Number init = {}) : result_(init) {}

    void Set(Number n){
        result_=n;
    }

    Number GetNumber() const{
        return result_;
    }

    bool GetHasMem() const {
        return mem_.has_value();
    }

    std::optional<Error> Add(Number n){
        result_+=n;
        return std::nullopt;
    }

    std::optional<Error> Sub(Number n){
        result_-=n;
        return std::nullopt;
    }

    std::optional<Error> Div(Number n){
        if constexpr (std::is_integral_v<Number> || std::is_same_v<Number,Rational>){
            if(n==0){
                return "Division by zero";
            }
        }
        result_/=n;
        return std::nullopt;
    }

    std::optional<Error> Mul(Number n){
        result_*=n;
        return std::nullopt;
    }

    std::optional<Error> Pow(Number n){

        if constexpr(std::is_integral_v<Number>){
            if (n<0){
                return "Integer negative power";
            }
            if (result_ == 0 && n == 0) {
                return "Zero power to zero";
            }
            result_=IntegerPow(result_,n);

        }
        else if constexpr(std::is_same_v<Number,Rational>){
            if(n.GetDenominator()!=1){
                return "Fraction power is not supported";
            }
            if (result_ == 0 && n == 0) {
                return "Zero power to zero";
            }
            result_=::Pow(result_,n);
        }
        else{
            result_=std::pow(result_,n);
        }
        return std::nullopt;
    }

    void Save(){
        mem_=result_;
    }

    void Load(){
        assert(mem_.has_value());
        result_ = mem_.value();
    }

    std::string GetNumberRepr() const{
        std::string result_now=std::to_string(result_);
        return result_now;
    }

private:
    Number result_=0;
    std::optional<Number> mem_;
};


