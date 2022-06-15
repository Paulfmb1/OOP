#include <iostream>
#include <fstream>

using namespace std;

struct Student {

    int age = 0;
    float progress = 0;
    int course = 0;
    char name[20]{};
    char surname[20]{};
    char patronymic[20]{};
    bool gender = false;

    Student() {}

};



void Add(fstream& file)
{
    Student student;

    cout << "Name: ";
    cin >> student.name;
    file << student.name << " ";

    cout << "Surname: ";
    cin >> student.surname;
    file << student.surname << " ";

    cout << "Patronymic: ";
    cin >> student.patronymic;
    file << student.patronymic << " ";

    cout << "Age: ";
    cin >> student.age;
    file << student.age << " ";
  
    cout << "Progress: ";
    cin >> student.progress;
    file << student.progress << " ";

    cout << "Course: ";
    cin >> student.course;
    file << student.course << " ";

    cout << "Gender: ";
    cin >> student.gender;
    if (student.gender)
        file << "Man" << endl;
    else
        file << "Woman" << endl;

    file.seekg(0, ios::end);
    file.flush();

}

void Print(fstream& file)
{
    system("cls");
    file.seekg(0, ios::beg);
    cout << "----------ALL STUDENTS----------" << endl;
    while (file)
    {
        char Human[6]{};
        Student student;
        file >> student.name;
        file >> student.surname;
        file >> student.patronymic;
        file >> student.age;
        file >> student.progress;
        file >> student.course;
        file >> Human;

        if (!file.good()) 
        {
            break;
        }
        cout << student.name << " ";
        cout << student.surname << " ";
        cout << student.patronymic << " ";
        cout << student.age << " ";
        cout << student.progress << " ";
        cout << student.course << " ";
        cout << Human << endl;

    }

    cout << "-----------------------------" << endl;

    file.clear();
    file.seekg(0, ios::beg);

}

void Task(fstream& file, ofstream& result)
{
    file.seekg(0, ios::beg);
    while (!file.eof()) {
        char Human[6]{};
        Student student;
        file >> student.name;
        file >> student.surname;
        file >> student.patronymic;
        file >> student.age;
        file >> student.progress;
        file >> student.course;
        file >> Human;

        if (!file.good()) {
            break;
        }

        if (student.progress > 8.4)
            result << student.name << " " << student.surname << " " << student.patronymic << endl;

    }

    file.clear();
    file.seekg(0, ios::beg);
    result.flush();
}



int main()
{
    bool isWorking = true;
    fstream OutputFile;
    ofstream Result("Result.txt", ios::app);
    OutputFile.open("1_4.txt", ios::in | ios::out | ios::app);

    while (isWorking)
    {
        cout << "1. Add\n"
            << "2. Print\n"
            << "3. Task\n"
            << "4. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Add(OutputFile);
            break;
            system("cls");
        }

        case 2:
        {
            Print(OutputFile);
            break;
        }

        case 3:
        {
            Task(OutputFile, Result);
            break;
        }


        case 4:
        {
            OutputFile.close();
            Result.close();
            isWorking = false;
            system("cls");
            break;
        }

        }
    }
}