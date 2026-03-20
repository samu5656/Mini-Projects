/*
Library Book Management System (C++ OOP)

This project is a simple Library Management System implemented using Object-Oriented Programming in C++. 
It manages books and users, allowing operations like adding books, registering users, issuing books, 
returning books, and displaying book details.

Each book has an ID, name, author, and availability status, while each user has an ID, name, 
and a limit of issuing up to 2 books. The system ensures that a book can only be issued if it is 
available and validates both book and user before performing any operation, maintaining consistency.

The project uses three main classes:
- Book: Handles book details and status (issued/available)
- User: Manages user information and number of books issued
- Library: Controls overall operations using vectors to store books and users

This project demonstrates key OOP concepts like encapsulation, class interaction, 
and efficient data management.
*/

#include <bits/stdc++.h>
using namespace std;
class book
{
    int id;
    string name;
    string author;
    bool isIssued;

public:
    void addbook(int i, string n, string a, bool b)
    {
        id = i;
        name = n;
        author = a;
        isIssued = b;
    }
    void displaybook()
    {
        cout << "\nBook id: " << id;
        cout << "\nBook name: " << name;
        cout << "\nBook author: " << author;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }
    bool status()
    {
        return isIssued;
    }
    int getid()
    {
        return id;
    }
    void issuebook()
    {
        isIssued = true;
    }
    void returnbook()
    {
        isIssued = false;
    }
};
class user
{
    int userID;
    string username;
    int booksIssued;

public:
    void adduser(int id, string name, int count)
    {
        userID = id;
        username = name;
        booksIssued = count;
    }
    void displayuser()
    {
        cout << "\nUser ID: " << userID;
        cout << "\nUser Name: " << username;
        cout << "\nNumber of books issued: " << booksIssued;
    }
    int getcount()
    {
        return booksIssued;
    }
    int getuserID()
    {
        return userID;
    }
    void addbooks()
    {
        booksIssued++;
    }
    void removebooks()
    {
        if (booksIssued > 0)
            booksIssued--;
    }
};

class library
{
    vector<book> books;
    vector<user> users;

public:
    void addbook()
    {
        int a;
        string x, y;
        cout << "\nEnter the Book id: ";
        cin >> a;
        cout << "\nEnter name of the Book: ";
        cin.ignore();
        getline(cin, x);
        cout << "\nEnter Book author: ";
        getline(cin, y);
        book b;
        b.addbook(a, x, y, false);
        books.push_back(b);
    }
    void adduser()
    {
        int a;
        string s;
        cout << "\nEnter user ID: ";
        cin >> a;
        cout << "\nEnter user name: ";
        cin.ignore();
        getline(cin, s);
        user u;
        u.adduser(a, s, 0);
        users.push_back(u);
    }
    void issuebook()
    {
        int i, n;
        cout << "\nEnter book ID: ";
        cin >> i;
        cout << "\nEnter user ID: ";
        cin >> n;
        int bookindex = -1;
        for (int j = 0; j < books.size(); j++)
        {
            if (books[j].getid() == i)
            {
                bookindex = j;
                if (books[j].status())
                {
                    cout << "Book already issued";
                    return;
                }
                break;
            }
        }
        if (bookindex == -1)
        {
            cout << "Book not found";
            return;
        }
        bool found = false;
        int userindex = -1;
        for (int l = 0; l < users.size(); l++)
        {
            if (users[l].getuserID() == n)
            {
                found = true;
                int count = users[l].getcount();
                if (count >= 2)
                {
                    cout << "\nYou can't take more than two books";
                    return;
                }
                else
                {
                    userindex = l;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "\nUser not found";
            return;
        }
        books[bookindex].issuebook();
        users[userindex].addbooks();
        cout << "\nBook issued successfully. User details: ";
        users[userindex].displayuser();
    }
    void returnbook()
    {
        int id, uid;
        cout << "\nEnter book ID: ";
        cin >> id;
        cout << "\nEnter user ID: ";
        cin >> uid;
        bool bookfound = false;
        bool userfound = false;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getid() == id)
            {
                bookfound = true;
                if (!books[i].status())
                {
                    cout << "\nBook already returned";
                    return;
                }
                books[i].returnbook();
                cout << "Book returned successfully";
                break;
            }
        }
        if (!bookfound)
        {
            cout << "\nBook not found";
            return;
        }
        for (int j = 0; j < users.size(); j++)
        {
            if (users[j].getuserID() == uid)
            {
                userfound = true;
                users[j].removebooks();
                break;
            }
        }
        if (!userfound)
        {
            cout << "\nUser not found";
            return;
        }
    }
    void displaybooks()
    {
        if (books.size() == 0)
        {
            cout << "\nNo books found";
            return;
        }
        for (int i = 0; i < books.size(); i++)
        {
            books[i].displaybook();
        }
    }
};
int main()
{
    library l;
    while (true)
    {
        int a;
        cout << "\n\nEnter 1 to add books\nEnter 2 to add users\nEnter 3 to Issue a book\nEnter 4 to return a book\nEnter 5 to display books\nEnter 6 to exit: ";
        cin >> a;
        switch (a)
        {
        case 1:
            l.addbook();
            break;
        case 2:
            l.adduser();
            break;
        case 3:
            l.issuebook();
            break;
        case 4:
            l.returnbook();
            break;
        case 5:
            l.displaybooks();
            break;
        case 6:
            exit(0);
        default:
            cout << "Enter valid number";
            break;
        }
    }
}