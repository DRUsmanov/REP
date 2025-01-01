#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    string input_string="abba";
    map<char,int> longest_substring;
    int counter = 0;
    int cash = 0;
    int result = 0;
    for (int i = 0;i < input_string.size();i++) {
        if (!longest_substring.count(input_string[i])) {
            longest_substring[input_string[i]]=i+1;
            counter = i + 1 - cash;
        }
        else {
            if (longest_substring[input_string[i]] > cash) {
                cash = longest_substring[input_string[i]];
            }
            counter = i + 1 - cash;
            /*longest_substring.erase(input_string[i]);*/
            longest_substring[input_string[i]] = i + 1;
            
        }
        if (result < counter) {
            result = counter;
        }
    }

    cout << result;

    return 0;
}

