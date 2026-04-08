#pragma once

#include <numeric>
#include <cstdint>
#include <cstdlib>
#include <iostream>


class Rational {
public:
    Rational() : numerator_(0), denominator_(1) { }

    Rational(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
        if (denominator_ == 0) {
            std::abort();
        }
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        Reduction();
    }

    Rational(int value): numerator_(value) , denominator_(1) {}

    Rational(const Rational& other) = default;

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

    Rational Inv() const {
        if (numerator_ == 0) {
            std::abort();
        }
        return Rational(denominator_, numerator_);
    }

    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

    Rational& operator+=(const Rational& r){
        numerator_ = numerator_ * r.denominator_ + r.numerator_ * denominator_;
        denominator_=denominator_*r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator-=(const Rational& r){
        numerator_ = numerator_ * r.denominator_ - r.numerator_ * denominator_;
        denominator_=denominator_*r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational& r){
        numerator_=numerator_*r.numerator_;
        denominator_=denominator_*r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational& r){
        numerator_=numerator_*r.denominator_;
        denominator_=denominator_*r.numerator_;
        Reduction();
        return *this;
    }

    Rational operator+(const Rational& r2) const {
        Rational other{*this};
        other += r2;
        return other;
    }

    Rational operator-(const Rational& r2) const {
        Rational other{*this};
        other -= r2;
        return other;
    }

    Rational operator*(const Rational& r2) const {
        Rational other{*this};
        other *= r2;
        return other;
    }

    Rational operator/(const Rational& r2) const {
        Rational other{*this};
        other /= r2;
        return other;
    }

    Rational operator+()const{
        return *this;
    }

    Rational operator-(){
        return Rational{-numerator_,denominator_};
    }

    friend std::istream& operator>>(std::istream& is, Rational& rate);
    friend std::ostream& operator<<(std::ostream& os, const Rational& rate);

    Rational& operator=(const int value){
        numerator_=value;
        denominator_=1;
        return *this;
    }

    Rational& operator=(const Rational& other) = default;

private:
    int numerator_=0;
    int denominator_=1;
};

inline std::istream& operator>>(std::istream& is, Rational& rat){
    int num, denum;
    char slash;
    is >> num >> slash;
    if (is.fail()){
        is.clear();
        rat.numerator_ = num;
    }
    else if (slash!='/'){
        is.unget();
        rat.numerator_ = num;
    }else{
        is >> denum;
        if (denum == 0) {
            is.setstate(std::ios::failbit);
        }
        rat.numerator_ = num;
        rat.denominator_ = denum;
    }
    rat.Reduction();
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational& rat){
    os << rat.numerator_;
    if( rat.denominator_==1){
        return os;
    } else{
        os<< " / " << rat.denominator_;
        return os;
    }
}

inline auto operator<=>(const Rational& db1, const Rational& db2) {
    return static_cast<std::int64_t>(db1.GetNumerator()) * db2.GetDenominator() <=>
           static_cast<std::int64_t>(db2.GetNumerator()) * db1.GetDenominator();
}

inline bool operator==(const Rational& db1, const Rational& db2) {
    return static_cast<std::int64_t>(db1.GetNumerator()) * db2.GetDenominator() ==
           static_cast<std::int64_t>(db2.GetNumerator()) * db1.GetDenominator();
}
