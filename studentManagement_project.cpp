#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    int id;
    string name;
    string course;
    int age;
    float marks;
};

Student s[100];
int countStudents = 0;

// Load data from file
void loadFromFile()
{
    ifstream file("students.txt");

    countStudents = 0;

    while (file >> s[countStudents].id)
    {
        file.ignore();

        getline(file, s[countStudents].name);
        getline(file, s[countStudents].course);

        file >> s[countStudents].age;
        file >> s[countStudents].marks;

        file.ignore();

        countStudents++;
    }

    file.close();
}

// Save data to file
void saveToFile()
{
    ofstream file("students.txt");

    for (int i = 0; i < countStudents; i++)
    {
        file << s[i].id << endl;
        file << s[i].name << endl;
        file << s[i].course << endl;
        file << s[i].age << endl;
        file << s[i].marks << endl;
    }

    file.close();
}

// Add Student
void addStudent()
{
    cout << "\nEnter Student ID: ";
    cin >> s[countStudents].id;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, s[countStudents].name);

    cout << "Enter Course: ";
    getline(cin, s[countStudents].course);

    cout << "Enter Age: ";
    cin >> s[countStudents].age;

    cout << "Enter Marks: ";
    cin >> s[countStudents].marks;

    countStudents++;

    saveToFile();

    cout << "\nStudent Added Successfully!\n";
}

// Display Students
void displayStudents()
{
    if (countStudents == 0)
    {
        cout << "\nNo Records Found!\n";
        return;
    }

    cout << "\n===== STUDENT RECORDS =====\n";

    for (int i = 0; i < countStudents; i++)
    {
        cout << "\nID     : " << s[i].id;
        cout << "\nName   : " << s[i].name;
        cout << "\nCourse : " << s[i].course;
        cout << "\nAge    : " << s[i].age;
        cout << "\nMarks  : " << s[i].marks << endl;
    }
}

// Search Student
void searchStudent()
{
    int id;
    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (s[i].id == id)
        {
            cout << "\nStudent Found!\n";
            cout << "ID     : " << s[i].id << endl;
            cout << "Name   : " << s[i].name << endl;
            cout << "Course : " << s[i].course << endl;
            cout << "Age    : " << s[i].age << endl;
            cout << "Marks  : " << s[i].marks << endl;
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

// Update Student
void updateStudent()
{
    int id;

    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (s[i].id == id)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, s[i].name);

            cout << "Enter New Course: ";
            getline(cin, s[i].course);

            cout << "Enter New Age: ";
            cin >> s[i].age;

            cout << "Enter New Marks: ";
            cin >> s[i].marks;

            saveToFile();

            cout << "\nRecord Updated Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

// Delete Student
void deleteStudent()
{
    int id;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (s[i].id == id)
        {
            for (int j = i; j < countStudents - 1; j++)
            {
                s[j] = s[j + 1];
            }

            countStudents--;

            saveToFile();

            cout << "\nRecord Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

int main()
{
    loadFromFile();

    int choice;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
