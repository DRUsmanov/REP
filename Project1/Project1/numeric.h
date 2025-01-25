#pragma once
// Разместите здесь встраиваемую функцию bool IsPrime(int number).

inline bool IsPrime(int number) {
    int i = 2;
    while (i < number) {
        if (number % i == 0) {
            return false;
        }
        else if (i == number - 1) return true;
        ++i;
    }
    return false;
}
