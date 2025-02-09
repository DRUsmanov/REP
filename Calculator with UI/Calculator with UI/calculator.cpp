#include "calculator.h"
#include <cmath>

void Calculator::Set(Number n) {
    current_number_ = n;
}

Number Calculator::GetNumber() const {
    return current_number_;
}

void Calculator::Add(Number n) {
    current_number_ += n;
}

void Calculator::Sub(Number n) {
    current_number_ -= n;
}

void Calculator::Div(Number n) {
    current_number_ /= n;
}

void Calculator::Mul(Number n) {
    current_number_ *= n;
}

void Calculator::Pow(Number n) {
    current_number_ = std::pow(current_number_, n);
}

void Calculator::Save() {
    memory_number_ = current_number_;
    memory_status_ = true;
}

void Calculator::Load() {
    current_number_ = memory_number_;
}

bool Calculator::HasMem() const {
    return memory_status_;
}

std::string Calculator::GetNumberRepr() const {
    std::string result = std::to_string(current_number_);
    return result;
}