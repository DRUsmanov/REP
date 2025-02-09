#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

#include "book.h"

// Записывает книгу в переданный поток.
void WriteBook(std::ostream& out, const Book& book) {
    // Реализуйте эту функцию самостоятельно.
    out << book.title << "\n" << book.author << "\n" << book.publication_year << "\n";
}

// Считывает книгу из переданного потока.
Book ReadBook(std::istream& in) {
    // Реализуйте эту функцию самостоятельно.
    Book book;
    in >> book.title >> book.author >> book.publication_year;
    return book;
}

// Сериализует книгу в строку.
std::string BookToString(const Book& book) {
    // Реализуйте эту функцию самостоятельно.
    std::string str;
    std::ostringstream out;
    WriteBook(out, book);
    str = out.str();
    return str;
}

// Десериализует книгу из строки.
Book StringToBook(const std::string& str) {
    // Реализуйте эту функцию самостоятельно.
    std::istringstream in{ str };
    Book book = ReadBook(in);
    return book;
}

bool BooksAreEqual(const Book& book1, const Book& book2) {
    return (book1.title == book2.title) && (book1.author == book2.author)
        && (book1.publication_year == book2.publication_year);
}

int main() {
    using namespace std::literals;

    const Book book1{ .title = "White Fang"s, .author = "Jack London"s, .publication_year = 1906 };
    const Book book2{ .title = "Moby-Dick"s, .author = "Herman Melville"s, .publication_year = 1851 };

    {
        std::stringstream strm;
        WriteBook(strm, book1);
        WriteBook(strm, book2);

        auto book1_copy = ReadBook(strm);
        auto book2_copy = ReadBook(strm);

        assert(BooksAreEqual(book1_copy, book1));
        assert(BooksAreEqual(book2_copy, book2));
    }

    {
        const std::string serializedBook = BookToString(book1);
        const Book deserializedBook = StringToBook(serializedBook);
        assert(BooksAreEqual(book1, deserializedBook));
    }
}