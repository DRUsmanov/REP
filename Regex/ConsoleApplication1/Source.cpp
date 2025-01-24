#include <iostream>
#include <regex>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    std::string line;
    std::getline(std::cin, line);

       
    const regex pattern(
        R"(^[a-zA-Z0-9._+-]+@)"
        R"([a-zA-Z0-9_+-]+\.[a-zA-Z0-9_.+-]+[a-zA-Z0-9_+-]+$)"
    );
    const regex pattern1(
        R"(^[a-zA-Z0-9._+-]+)"
    );
    const regex pattern2(
        R"([a-zA-Z0-9_+-]+\.[a-zA-Z0-9_.+-]+[a-zA-Z0-9_+-]+$)"
    );
    smatch result;
    if (regex_match(line, pattern)) {
        regex_search(line, result, pattern1);
        cout << result[0] << endl;
        regex_search(line, result, pattern2);
        cout << result[0] << endl;
    }
    else {
        cout << "Некорректный email" << endl;
    }
}