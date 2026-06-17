#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }
};

class Member {
public:
    int id;
    string name;

    Member(int i, string n) {
        id = i;
        name = n;
    }
};

vector<Book> books;
vector<Member> members;

void addBook() {
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "Book Added Successfully!\n";
}

void addMember() {
    int id;
    string name;

    cout << "Enter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));

    cout << "Member Added Successfully!\n";
}

void issueBook() {
    int id;

    cout << "Enter Book ID to Issue: ";
    cin >> id;

    for (auto &book : books) {
        if (book.id == id) {
            if (!book.issued) {
                book.issued = true;
                cout << "Book Issued Successfully!\n";
            } else {
                cout << "Book Already Issued!\n";
            }
            return;
        }
    }

    cout << "Book Not Found!\n";
}

void returnBook() {
    int id;

    cout << "Enter Book ID to Return: ";
    cin >> id;

    for (auto &book : books) {
        if (book.id == id) {
            if (book.issued) {
                book.issued = false;
                cout << "Book Returned Successfully!\n";
            } else {
                cout << "Book Was Not Issued!\n";
            }
            return;
        }
    }

    cout << "Book Not Found!\n";
}

void searchByTitle() {
    string title;

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);

    for (auto &book : books) {
        if (book.title == title) {
            cout << "\nBook Found\n";
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            return;
        }
    }

    cout << "Book Not Found!\n";
}

void searchByAuthor() {
    string author;

    cin.ignore();
    cout << "Enter Author Name: ";
    getline(cin, author);

    for (auto &book : books) {
        if (book.author == author) {
            cout << "\nBook Found\n";
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
        }
    }
}

void displayBooks() {
    cout << "\n----- Books List -----\n";

    for (auto &book : books) {
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Author: " << book.author
             << " | Status: "
             << (book.issued ? "Issued" : "Available")
             << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search By Title\n";
        cout << "6. Search By Author\n";
        cout << "7. Display Books\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addMember();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                searchByTitle();
                break;
            case 6:
                searchByAuthor();
                break;
            case 7:
                displayBooks();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
