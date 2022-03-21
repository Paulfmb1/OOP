#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Student {

    int age = 0;
    float progress = 0;
    int course = 0;
    char name[20]{};
    char surname[20]{};
    char patronymic[20]{};
    bool gender = false;

    Student() = default;

    Student(std::ifstream& str) 
    { 
        str.read(reinterpret_cast<char*>(this), sizeof(Student));
    }

};
#pragma pack(pop)

std::fstream& operator >> (std::fstream& str, Student& stud) {
    str.read(reinterpret_cast<char*>(&stud), sizeof(Student));
    return str;
}

int main() {

    bool isWorking = true;
    bool isPaused = false;
    fstream outputFileStream("database", ios::in | ios::out | ios::app | ios::binary);
    ofstream outputResultStream("result.txt", ios::app | ios::binary);

    while (isWorking) {

        cout << "1. Add\n"
            << "2. Print\n"
            << "3. Task\n"
            << "4. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {

        case 1: {

            Student student;
            cout << "Name: ";
            cin >> student.name;

            cout << "Surname: ";
            cin >> student.surname;

            cout << "Patronymic: ";
            cin >> student.patronymic;

            cout << "Age: ";
            cin >> student.age;

            cout << "Progress: ";
            cin >> student.progress;

            cout << "Course: ";
            cin >> student.course;

            cout << "Gender: ";
            cin >> student.gender;

            outputFileStream.seekg(0, ios::end);
            outputFileStream.write(reinterpret_cast<char*>(&student), sizeof(student));
            outputFileStream.flush();
            break;

        }

        case 2: {         // ���� �� ��������. ������? � ���� ����� �� ������

            system("cls");
            outputFileStream.seekg(0, ios::beg);
            cout << "----------ALL STUDENTS----------" << endl;
            while (outputFileStream) {
                Student student;
                outputFileStream >> student;

                if (!outputFileStream.good()) {
                    break;
                }

                cout << "-----------------------------" << endl;
                cout << student.name << endl;
                cout << student.surname << endl;
                cout << student.patronymic << endl;
                cout << student.age << endl;
                cout << student.progress << endl;
                cout << student.course << endl;
                cout << student.gender << endl;

            }

            cout << "-----------------------------" << endl;

            outputFileStream.clear();
            outputFileStream.seekg(0, ios::beg);
            isPaused = true;
            cin.get();
            break;

        }

        case 3:
        {
            outputFileStream.seekg(0, ios::beg);
            while (!outputFileStream.eof()) {
                Student student;
                outputFileStream >> student;

                if (!outputFileStream.good()) {
                    break;
                }

                if (student.progress > 8.4)
                    outputResultStream << student.name << " " << student.surname << " " << student.patronymic << endl;

            }

            outputFileStream.clear();
            outputFileStream.seekg(0, ios::beg);
            outputResultStream.flush();

            break;
        }

        case 4:
        {
            outputFileStream.close();
            outputResultStream.close();
            exit(0);
            break;
        }

        }

        if (isPaused) 
        {
            cin.clear();
            fflush(stdin);
            cin.get();
            isPaused = false;
        }

        system("cls");

    }

}