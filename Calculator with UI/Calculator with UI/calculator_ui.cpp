#include "calculator_ui.h"

using namespace std::literals;

bool CalculatorUI::Parse(std::istream& input) {
    Number operand;
    if (ReadNumber(input, operand)) {
        calc_.Set(operand);
    }

    std::string token;

    while (input >> token) {
        if (token == "+"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Add(operand);
        }
        else if (token == "-"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Sub(operand);
        }
        else if (token == "*"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Mul(operand);
        }
        else if (token == "/"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Div(operand);
        }
        else if (token == "**"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Pow(operand);
        }
        else if (token == "s"s) {
            calc_.Save();
        }
        else if (token == "l"s) {
            if (!calc_.HasMem()) {
                err_ << "Error: Memory is empty"s << "\n";
                break;
            }
            calc_.Load();
        }
        else if (token == "="s) {
            out_ << calc_.GetNumberRepr() << "\n";
        }
        else if (token == "c"s) {
            calc_.Set(0);
        }
        else if (token == "n"s) {
            calc_.Set(-calc_.GetNumber());
        }
        else if (token == ":"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Set(operand);
        }
        else if (token == "q"s) {
            return true;
        }
        else {
            err_ << "Error: Unknown token "s << "'" << token << "'" << std::endl;
            return false;
        }
    }
      
    return !input;
}

bool CalculatorUI::ReadNumber(std::istream& input, Number& result) const {
    if (!(input >> result)) {
        input.clear();
        err_ << "Error: Numeric operand expected" << "\n";
        return false;
    }
    return true;
}

void CalculatorUI::Help() const {
    auto help_text = "Commands:\n"s
        "= - show current number\n"s
        "+ - * / ** <number> - perform operation over current number\n"s
        "s - save to memory\n"s
        "l - load from memory\n"s
        "c - clear\n"s
        "n - negate number\n"s
        ": <number> - set current number\n"s
        "h - show help\n"
        "q - exit"s;
    out_ << help_text << "\n";
}