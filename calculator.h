#include <string>
using Number=double;
using Sign=std::string;

bool ReadNumber(Number& result);
bool ReadSign(Sign& operation);
Sign Save(Number result);
bool Load(Sign memory, Number& result);
void Print (Number result);
bool RunCalculatorCycle();
