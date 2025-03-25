#include <iostream>
#include <memory>
#include <string>

class Book {
public:
    std::string title;

    Book(std::string t) : title(t) {
        std::cout << "Book '" << title << "' Created\n";
    }

    ~Book() {
        std::cout << "Book '" << title << "' Destroyed\n";
    }

    void show() {
        std::cout << "Book Title: " << title << "\n";
    }
};

class Student {
public:
    std::string name;
    std::shared_ptr<Book> borrowedBook;

    Student(std::string n) : name(n) {}

    void borrowBook(std::shared_ptr<Book> book) {
        borrowedBook = book;
        std::cout << name << " borrowed '" << borrowedBook->title << "'\n";
    }

    void showBook() {
        if (borrowedBook) {
            std::cout << name << " has ";
            borrowedBook->show();
        } else {
            std::cout << name << " has no book.\n";
        }
    }
};



// Function to transfer book ownership
void transferBook(std::shared_ptr<Book> book, Student &from, Student &to) {
    if (from.borrowedBook == book) {
        from.borrowedBook.reset();  // Reduce reference count
        to.borrowBook(book);  // Transfer ownership
    } else {
        std::cout << from.name << " does not have this book.\n";
    }
}

int main() {
    std::shared_ptr<Book> book1 = std::make_shared<Book>("C++ Programming");

    Student s1("Alice");
    Student s2("Bob");

    s1.borrowBook(book1);
    s1.showBook();
    s2.showBook();

    std::cout << "\nTransferring book from Alice to Bob...\n";
    transferBook(book1, s1, s2);

    s1.showBook();
    s2.showBook();

    std::cout << "\nEnd of program.\n";
    return 0;
}
