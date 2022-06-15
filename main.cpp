#include <iostream>
#include <map>
#include <fstream>
#include "Lab41.h"
#include "Vector.h"

using namespace std;

class ObjectFactory
{
protected:
    const size_t SIZE = 255;
public:
    virtual Object* Create(ifstream& ifs) = 0;
};

class HumanFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        unsigned short isMan;
        unsigned short isChildren;
        unsigned short isHaveGlasses;
        unsigned short isHaveBeard;

        ifs >> isMan;
        ifs >> isChildren;
        ifs >> isHaveGlasses;
        ifs >> isHaveBeard;

        double Xmin;
        double Xmax;
        double Ymin;
        double Ymax;

        ifs >> Xmin;
        ifs >> Xmax;
        ifs >> Ymin;
        ifs >> Ymax;

        Position pos(Xmin, Xmax, Ymin, Ymax);

        Object* Temp = new Human(isMan, isChildren, isHaveGlasses, isHaveBeard, pos);

        return Temp;
    }
};

class CyclistFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        const size_t SIZE = 255;
        char* bike_color = new char[SIZE];
        ifs.get();
        ifs.getline(bike_color, SIZE);

        unsigned short isMan;
        unsigned short isChildren;
        unsigned short isHaveGlasses;
        unsigned short isHaveBeard;

        ifs >> isMan;
        ifs >> isChildren;
        ifs >> isHaveGlasses;
        ifs >> isHaveBeard;
     
        double Xmin;
        double Xmax;
        double Ymin;
        double Ymax;

        ifs >> Xmin;
        ifs >> Xmax;
        ifs >> Ymin;
        ifs >> Ymax;
        Position pos(Xmin, Xmax, Ymin, Ymax);

        Object* Temp = new Cyclist(isMan, isChildren, isHaveGlasses, isHaveBeard, pos, bike_color);

        return Temp;
    }
};

class CarFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        const size_t SIZE = 255;
        char* color = new char[SIZE];
        ifs.get();
        ifs.getline(color, SIZE);


        char* number = new char[SIZE];
        ifs.get();
        ifs.getline(number, SIZE);

        bool isTaxi;
        ifs >> isTaxi;

        double Xmin;
        double Xmax;
        double Ymin;
        double Ymax;


        ifs >> Xmin;
        ifs >> Xmax;

        ifs >> Ymin;
        ifs >> Ymax;
        Position pos(Xmin, Xmax, Ymin, Ymax);

        Object* Temp = new Car(number, isTaxi, color, pos);

        return Temp;
    }
};

class BagFactory : public ObjectFactory
{
public:
    Object* Create(ifstream& ifs)
    {
        const size_t SIZE = 255;
        char* time = new char[SIZE];
        ifs.getline(time, SIZE);

        double Xmin;
        double Xmax;
        double Ymin;
        double Ymax;

        ifs >> Xmin; 
        ifs >> Xmax;
        ifs >> Ymin;
        ifs >> Ymax;
        Position pos(Xmin, Xmax, Ymin, Ymax);
        Object* Temp = new Bag(time, pos);

        return Temp;
    }
};


class ObjectCollection : Vector<Object*>
{
private:
    Vector<Object*> _arr;

public:
    void push_back(Object* other) { _arr.push_back(other); }

    ObjectCollection(string name, map<string, ObjectFactory*>& factories)
    {
        ifstream stream;
        stream.open(name);

        if (stream.is_open())
        {
            string type;
            stream >> type;

            while (!stream.eof())
            {
                Object* temp = factories[type]->Create(stream);
                _arr.push_back(temp);
                stream >> type;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const ObjectCollection& vector)
    {
        for (size_t i = 0; i < vector._arr.getSize(); i++)
        {
            os << *vector._arr[i] << endl << endl;
        }
        return os;
    }

public:

    ObjectCollection() = default;

    ObjectCollection(ObjectCollection&& obj)
    {
        _arr = std::move(obj._arr);
    }

    ObjectCollection& operator=(ObjectCollection&& obj)
    {
        _arr = std::move(obj._arr);
        return *this;
    }

    void Save()
    {
        ofstream of("result.txt");
        int size = _arr.getSize();

        for (int i = 0; i < size; ++i)
            (*_arr[i]).Print(of);
    }
};


void Menu(ObjectCollection& col)
{
    bool x = true;

    while (x)
    {
        cout << "Enter the number:" << endl;
        cout << "1. Human\n"
            << "2. Cyclist\n"
            << "3. Car\n"
            << "4. Bag\n"
            << "5. Print\n"
            << "6. Exit\n"
            << "P.S.: (1 - yes, 2 - no, 3 - not defined)\n";

        size_t choose = 0;
        cin >> choose;

        switch (choose)
        {
        case 1:
        {
            unsigned short isMan;
            unsigned short isChildren;
            unsigned short isHaveGlasses;
            unsigned short isHaveBeard;

            cout << "Is man?:\t";
            cin >> isMan;
            cout << endl;

            cout << "Is children?:\t";
            cin >> isChildren;
            cout << endl;

            cout << "Is have glasses?:\t";
            cin >> isHaveGlasses;
            cout << endl;

            cout << "is have beard?:\t";
            cin >> isHaveBeard;
            cout << endl;

            double Xmin;
            double Xmax;
            double Ymin;
            double Ymax;

            cout << "Enter Xmin:\t";
            cin >> Xmin;
            cout << endl;

            cout << "Enter Xmax:\t";
            cin >> Xmax;
            cout << endl;

            cout << "Enter Ymin:\t";
            cin >> Ymin;
            cout << endl;

            cout << "Enter Ymax:\t";
            cin >> Ymax;
            cout << endl;
            Position pos(Xmin, Xmax, Ymin, Ymax);

            col.push_back(new Human(isMan, isChildren, isHaveGlasses, isHaveBeard, pos));

            break;

        }

        case 2:
        {

            const size_t SIZE = 255;
            char* bike_color = new char[SIZE];
            cin.get();
            cout << "Enter the bike color:\t";
            cin.getline(bike_color, SIZE);

            unsigned short isMan;
            unsigned short isChildren;
            unsigned short isHaveGlasses;
            unsigned short isHaveBeard;

            cout << "Is man?:\t";
            cin >> isMan;
            cout << endl;

            cout << "Is children?:\t";
            cin >> isChildren;
            cout << endl;

            cout << "Is have glasses?:\t";
            cin >> isHaveGlasses;
            cout << endl;

            cout << "is have beard?:\t";
            cin >> isHaveBeard;
            cout << endl;

            double Xmin;
            double Xmax;
            double Ymin;
            double Ymax;

            cout << "Enter Xmin:\t";
            cin >> Xmin;
            cout << endl;

            cout << "Enter Xmax:\t";
            cin >> Xmax;
            cout << endl;

            cout << "Enter Ymin:\t";
            cin >> Ymin;
            cout << endl;

            cout << "Enter Ymax:\t";
            cin >> Ymax;
            cout << endl;
            Position pos(Xmin, Xmax, Ymin, Ymax);

            col.push_back(new Cyclist(isMan, isChildren, isHaveGlasses, isHaveBeard, pos, bike_color));

            break;
        }

        case 3:
        {
            const size_t SIZE = 255;
            char* color = new char[SIZE];
            cin.get();
            cout << "Enter the color of the car:\t";
            cin.getline(color, SIZE);


            char* number = new char[SIZE];
            cin.get();
            cout << "Enter the number of car:\t";
            cin.getline(number, SIZE);

            bool isTaxi;
            cout << "Is taxi?(0 - no, 1 - yes):\t";
            cin >> isTaxi;

            double Xmin;
            double Xmax;
            double Ymin;
            double Ymax;

            cout << "Enter Xmin:\t";
            cin >> Xmin;
            cout << endl;

            cout << "Enter Xmax:\t";
            cin >> Xmax;
            cout << endl;

            cout << "Enter Ymin:\t";
            cin >> Ymin;
            cout << endl;

            cout << "Enter Ymax:\t";
            cin >> Ymax;
            cout << endl;
            Position pos(Xmin, Xmax, Ymin, Ymax);

            col.push_back(new Car(number, isTaxi, color, pos));
            break;
        }

        case 4:
        {
            const size_t SIZE = 255;
            char* time = new char[SIZE];
            cin.get();
            cout << "The time when it was first seen?:\t";
            cin.getline(time, SIZE);

            double Xmin;
            double Xmax;
            double Ymin;
            double Ymax;

            cout << "Enter Xmin:\t";
            cin >> Xmin;
            cout << endl;

            cout << "Enter Xmax:\t";
            cin >> Xmax;
            cout << endl;

            cout << "Enter Ymin:\t";
            cin >> Ymin;
            cout << endl;

            cout << "Enter Ymax:\t";
            cin >> Ymax;
            cout << endl;
            Position pos(Xmin, Xmax, Ymin, Ymax);

            col.push_back(new Bag(time, pos));

            break;
        }

        case 5:
        {
            cout << col << endl;
            break;
        }

        default:
        {
            x = false;
            col.Save();
            break;
        }        }
    }
}

int main()
{
    map<string, ObjectFactory*> Map;
    Map["Human"] = new HumanFactory;
    Map["Cyclist"] = new CyclistFactory;
    Map["Car"] = new CarFactory;
    Map["Bag"] = new BagFactory;

    ObjectCollection Temp("result.txt", Map);
    Menu(Temp);

    return 0;
}