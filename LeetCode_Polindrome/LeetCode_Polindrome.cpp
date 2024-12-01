#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string word{ "полпаплоп" };
    int i = (word.size() / 2);
    for (int s = 0; s < i; s++) {
        if (word[s] != word[word.size() - s - 1]) {
            cout << "This is not palindrome!";
            break;
        }
        if (s == i - 1) {
            cout << "This is palindrome!";
        }
    }
 return 0;
}
