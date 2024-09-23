 #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }

    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl;
    }
};

class Library {
private:
    vector<Book> books; 

public:
    void addBook(const Book &book) {
        books.push_back(book);
        cout << "Book added: " << book.getTitle() << endl;
    }

    void removeBook(const string &isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                cout << "Book removed: " << it->getTitle() << endl;
                books.erase(it);
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "Library is empty!" << endl;
        } else {
            cout << "Books in the Library: " << endl;
            for (const auto &book : books) {
                book.displayBook();
            }
        }
    }
};

void displayMenu() {
    cout << "\nLibrary Menu:" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Display all books" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library myLibrary;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  
        switch (choice) {
        case 1: {
            string title, author, isbn;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book ISBN: ";
            getline(cin, isbn);
            Book newBook(title, author, isbn);
            myLibrary.addBook(newBook);
            break;
        }
        case 2: {
            string isbn;
            cout << "Enter ISBN of the book to remove: ";
            getline(cin, isbn);
            myLibrary.removeBook(isbn);
            break;
        }
        case 3: {
            myLibrary.displayBooks();
            break;
        }
        case 4:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
