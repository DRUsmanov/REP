#include <iostream>
using namespace std;

class Solution {
public:
    string haystack;
    string needle;

    void index_of_first_element() {
        int index;
        for (int i = 0; i<haystack.size(); i++) {
            int x = 0;
            if (haystack[i] == needle[x]) {
                for (int j = i + 1; j <(i+needle.size()); j++) {
                    x++;
                    if (haystack[j] != needle[x]) {
                        break;
                    }
                }
            }
            if (x == needle.size()-1) {
                index = i;
                break;
            }
        }
        cout << index;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Solution problem;
    problem.haystack = { "новое предложение"};
    problem.needle = { "жен" };
    problem.index_of_first_element();

    return 0;

}
