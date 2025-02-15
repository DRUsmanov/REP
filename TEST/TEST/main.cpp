#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// Функции для более удобного чтения.
string ReadString() {
    string line;
    getline(cin, line);
    return line;
}

int ReadInteger() {
    string s = ReadString();
    return stoi(s);
}

// Переводит символ ch к верхнему регистру, если 
// это строчная буква английского алфавита, и возвращает
// его. В противном случае возвращает этот символ без изменения.
char ToUpper(unsigned char ch) {
    char cha = static_cast<char>(toupper(ch));
    return cha;
}

// Возвращает модифицированную копию строки s, в которой 
// каждый символ приведён к верхнему регистру
// функцией ToUpper(unsigned char). 
string ToUpper(string st) {
    using namespace std;
    for (size_t i = 0; i < st.size(); i++) {
        st[i] = ToUpper(st[i]);
    }
    return st;
}


void PrintBookInfo(const string& book_title,
    int publication_year,
    const string& author_name,
    int page_count) {
    using namespace std;
    cout << "Book title: "s << ToUpper(book_title) << endl;
    cout << "Author: "s << ToUpper(author_name) << endl;
    cout << "Pages: "s << page_count << endl;
    cout << "Published in: "s << publication_year << endl;
}

int main() {
    const string title = ReadString();
    const int publication_year = ReadInteger();
    const string author = ReadString();
    const int number_of_pages = ReadInteger();

    PrintBookInfo(title, publication_year, author, number_of_pages);
}