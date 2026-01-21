/*
Student Record Management System (C++)

This program demonstrates the use of classes and vectors in C++.
Each student is represented as an object of the `student` class, and
all student objects are stored dynamically using a `vector`.

The system allows the user to:
- Add student details (name, roll number, and marks)
- View all stored student records
- Search for a student
- Delete a student record

This project helps in understanding object-oriented programming concepts
and how vectors can be used to manage collections of objects efficiently.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;
class student
{
private:
    int roll_no;
    string name;
    int marks;

public:
    void add_student()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "\nEnter student roll_no: ";
        cin >> roll_no;
        cout << "\nEnter marks: ";
        cin >> marks;
    }
    void view_student()
    {
        cout << "\nRoll_no :  " << roll_no << "\nName :  " << name << "\nMarks :  " << marks;
    }
    int get_roll()
    {
        return roll_no;
    }
};
int main()
{
    vector<student> students;
    while (true)
    {
        int choice;
        cout << "\n Press 1 to ADD A STUDENT \n Press 2 to VIEW STUDENTS \n Press 3 to SEARCH A STUDENT \n Press 4 t0 DELETE A STUDENT \n Press 5 to EXIT\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            student s;
            s.add_student();
            students.push_back(s);
            break;
        }

        case 2:
        {
            for (auto &s : students)
            {
                s.view_student();
            }
            break;
        }

        case 3:
        {
            int search_roll;
            bool val = false;
            cout << "\nEnter student roll_no to search: ";
            cin >> search_roll;

            for (auto &s : students)
            {
                if (s.get_roll() == search_roll)
                {
                    cout << "\nMATCH FOUND";
                    s.view_student();
                    val = true;
                    break;
                }
            }
            if (!val)
            {
                cout << "\nNO MATCH FOUND";
            }
            break;
        }

        case 4:
        {
            int del;
            bool val = false;
            cout << "\n Enter student roll_no to delete: ";
            cin >> del;
            for (auto s = students.begin(); s != students.end(); ++s)
            {
                if (s->get_roll() == del)
                {
                    students.erase(s);
                    cout << "\nStudent record deleted succesfully";
                    val = true;
                    break;
                }
            }
            if (!val)
            {
                cout << "\nNO MATCH FOUND";
            }
            break;
        }

        case 5:
            exit(0);

        default:
            break;
        }
    }
}