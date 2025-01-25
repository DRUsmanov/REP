// Разместите здесь необходимые include-директивы.
#include <iostream>
#include <string>
#include "numeric.h"

int main() {
    using namespace std::literals;

    int n;
    std::cin >> n;
    if (IsPrime(n)) {
        std::cout << "prime"s << std::endl;
    }
    else {
        std::cout << "not prime"s << std::endl;
    }
}