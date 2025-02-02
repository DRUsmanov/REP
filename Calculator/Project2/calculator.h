// В этом файле объявления функций.
#pragma once
#include <string>
#include <vector>

using namespace std::literals;
using Number = double;

const auto err_not_number = "Error: Numeric operand expected"s;
const auto err_not_operation = "Error: Unknown token "s;
const auto err_memory_empty = "Error: Memory is empty"s;
const std::vector<std::string> correct_operation = { "+","-","*","/","**",":","c","q","=","s","l" };

bool ReadNumber(Number& result);

bool RunCalculatorCycle();

