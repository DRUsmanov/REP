#include <cassert>
#include <iostream>
#include <cctype>
#include <regex>
#include <algorithm>

using namespace std::literals;
const int MIN_BASE = 2;
const int MAX_BASE = 36;

// Переводит цифру из числового представления в символьное.
// Если digit находится в диапазоне 0..9, возвращает символ '0'..'9'.
// Если digit находится в диапазоне 10..35, возвращает символ 'A'..'Z'.
// В остальных случае возвращает символ '?'.
char DigitToChar(int digit) {
    if (digit < 0 || digit >= MAX_BASE) {
        return '?';
    }
    return static_cast<char>(digit <= 9 ? '0' + digit : (digit - 10) + 'A');
}

// Преобразует число number в строковое представление
// в системе счисления по основанию base.
// Если number отрицательное, перед ним должен быть символ «-».
// Гарантируется, что base лежит в диапазоне от 2 до 36.
// std::string NumberToString(int number, bool& was_error, int base = 10)
std::string NumberToString(int number, bool& was_error, int base = 10) {
    if (base < 2 || base > MAX_BASE) {
        was_error = true;
        return ""s;
    }

    const bool is_negative = number < 0;

    std::string str;
    do {
        int digit = number % base;  // Вычленяем последнюю цифру числа.

        // Цифра может получиться отрицательной, если число было отрицательным.
        // Поэтому передаём в DigitToChar её модуль.
        str = DigitToChar(is_negative ? -digit : digit) + str;
        number = number / base;  // Отбрасываем последнюю цифру.
    } while (number != 0);       // Повторяем, пока не дошли до нуля.

    if (is_negative) {
        str = '-' + str;
    }

    return str;
}

// Преобразует символ ch в цифру от 0 до 35 в системе счисления с основанием base.
// Если символ невалиден в этой системе счисления, функция должна вернуть -1.
// int CharToDigit(char ch, int base = 10)
int CharToDigit(char ch, bool& was_error, int base=10) {
    int digit=-1;
    if (ch >= '0' && ch <= '9') {
        digit= ch - '0';
    }
    else if (ch >= 'A' && ch <= 'Z') {
        digit= ch - 'A' + 10;
    }
    else {
        digit= ch - 'a' + 10;
    }
    if (digit >= 0 && digit < base) return digit;
    else {
        was_error = true;
        return -1;
    }
}

// Преобразует строку s, записанную в системе счисления base, в число.
// В начале строки s может находиться опциональный + или -.
// int StringToNumber(const std::string& s, bool& was_error, int base = 10)
int StringToNumber(const std::string& s, bool& was_error, int base = 10) {
    if (s.empty() || base < 2 || base > 36) {
        was_error = true;
        return 0;
    }
    if ((s[0] == '-' || s[0] == '+') && s.size() == 1) {
        was_error = true;
        return -1;
    }
    if (base > 10) {
        for (auto it : s) {
            if (it == '-' || it == '+') continue;
            if (it < '0' || std::toupper(it) > base + 54) {
                was_error = true;
                return 0;
            }
        }
    }
    if (base <= 10){
        for (auto it : s) {
            if (it == '-' || it == '+') continue;
            if (it < '0' || it >'9') {
                was_error = true;
                return 0;
            }
        }
    }
    size_t index = 0;
    bool is_negative = false;

    if (!s.empty()) {
        if (s[0] == '-') {
            ++index;
            is_negative = true;
        }
        else if (s[0] == '+') {
            ++index;
        }
    }

    int number = 0;
    for (; index < s.length(); ++index) {
        int digit = CharToDigit(s[index],was_error, base);
        if (is_negative) {
            digit = -digit;
        }
        number = number * base + digit;
    }
    return number;
}

// Преобразует число src_number, записанное в системе счисления src_base,
// в строковое представление этого же числа в системе счисления dst_base.
// std::string ConvertNotation(const std::string& src_number, int src_base = 10, int dst_base = 10)
std::string ConvertNotation(const std::string& src_number, int src_base = 10, int dst_base = 10) {
    bool was_error=false;
    int number = StringToNumber(src_number, was_error, src_base);
    std::string result;
    if (!was_error) {
        result= NumberToString(number, was_error, dst_base);
    }
    return was_error ? ""s : result;
}

// Обновлённая функция main.
int main() {
    
    std::string src_string;
    int src_base, dst_base;

    std::cin >> src_string >> src_base >> dst_base;
    std::string result = ConvertNotation(src_string, src_base, dst_base);
    if (!result.empty()) {
        std::cout << result << std::endl;
    }
    else {
        std::cout << "ERROR"s << std::endl;
    }
}