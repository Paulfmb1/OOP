#pragma once


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Check
{
	yes = 1,
	no,
	not_defined
};

class Position
{
private:

	double _Xmin = 0;
	double _Xmax = 0;
	double _Ymin = 0;
	double _Ymax = 0;

private:

public:

	Position() = default;

	Position(const double Xmin, const double Xmax, const double Ymin, const double Ymax)
	{
		while (Xmin > Xmax || Ymin > Ymax)
		{
			throw invalid_argument("Invalid argument");
		}

		this->_Xmin = Xmin;
		this->_Xmax = Xmax;
		this->_Ymin = Ymin;
		this->_Ymax = Ymax;
	}

	/*Position(const Position& other)
	{
		this->_Xmin = other.Get_Xmin();
		this->_Xmax = other.Get_Xmax();
		this->_Ymin = other.Get_Ymin();
		this->_Ymax = other.Get_Ymax();

	}

	Position(Position&& other)
	{
		if (this != &other)
		{
			this->_Xmin = other._Xmin;
			this->_Xmax = other._Xmax;
			this->_Ymin = other._Ymin;
			this->_Ymax = other._Ymax;
		}

	}

	Position& operator=(const Position& other)
	{
		if (this != &other)
		{
			Clear();
			this->_Xmin = other._Xmin;
			this->_Xmax = other._Xmax;
			this->_Ymin = other._Ymin;
			this->_Ymax = other._Ymax;
		}

		return *this;
	}

	Position& operator=(Position&& other)
	{
		if (this != &other)
		{
			Clear();
			this->_Xmin = other._Xmin;
			this->_Xmax = other._Xmax;
			this->_Ymin = other._Ymin;
			this->_Ymax = other._Ymax;
		}

		return *this;

	}*/

	double Get_Xmin() const { return _Xmin; }
	double Get_Xmax() const { return _Xmax; }
	double Get_Ymin() const { return _Ymin; }
	double Get_Ymax() const { return _Ymax; }

	Position(ifstream& stream)
	{
		stream >> _Xmin;
		stream >> _Xmax;
		stream >> _Ymin;
		stream >> _Ymax;
	}

	void Set_Xmin(const double Xmin) { _Xmin = Xmin; }
	void Set_Xmax(const double Xmax) { _Xmax = Xmax; }
	void Set_Ymin(const double Ymin) { _Ymin = Ymin; }
	void Set_Ymax(const double Ymax) { _Ymax = Ymax; }



	void Clear()
	{
		_Xmin = 0;
		_Xmax = 0;
		_Ymin = 0;
		_Ymax = 0;
	}


	friend std::ostream& operator<<(std::ostream& str, const Position& p)
	{
		str << "Xmin = " << p.Get_Xmin() << "\tXmax = " << p.Get_Xmax() << "\tYmin = " << p.Get_Ymin() << "\tYmax = " << p.Get_Ymax();
		return str;
	}

	virtual ~Position() = default;

};


class Object
{
protected:

	Position _pos;

public:

	Object() = default;

	Object(const Position& pos)
	{
		this->_pos = pos;
	}

	Object(const Object& obj)
	{
		this->_pos = obj._pos;
	}
	/*
	Object(Object&& other)
	{
		if (this != &other)
		{
			this->_pos = other._pos;
		}
	}

	Object& operator=(const Object& other)
	{
		if (this != &other)
		{
			this->_pos = other._pos;
		}

		return *this;
	}

	Object& operator=(const Object& other)
	{
		if (this != &other)
		{
			this->_pos = other._pos;
		}

		return *this;
	}*/


	friend std::ostream& operator << (std::ostream& str, const Object& o) 
	{
		o.Print(str);
		return str;
	}

	friend std::ofstream operator << (std::ofstream& stream, const Object& obj) {
		stream << obj._pos.Get_Xmax() << " " << obj._pos.Get_Xmin() << " " << obj._pos.Get_Ymax() << " " << obj._pos.Get_Ymin();

	}

	virtual ~Object() = default;

public:

	virtual void Print(std::ostream& str) const
	{
		str << _pos;
	}

private:

	void Clear()
	{
		_pos.Clear();
	}

};


class Inanimate_Object : public Object
{
protected:

	 char* _color = nullptr;

public:

	Inanimate_Object(char* color, const Position& pos) : Object(pos)
	{
		this->_color = color;
	}

	Inanimate_Object(Inanimate_Object& other) : Object(other._pos)
	{                          
		this->_color = other._color;
	}

	friend  std::ostream& operator << (std::ostream& str, const Inanimate_Object& o)
	{
		o.Print(str);
		return str;
	}

	friend std::ofstream operator << (std::ofstream& stream, const Inanimate_Object& obj) {
		stream << obj._pos.Get_Xmax() << " " << obj._pos.Get_Xmin() << " " << obj._pos.Get_Ymax() << " " << obj._pos.Get_Ymin() << " " << obj._color;
	}

	void Print(std:: ostream& str) const override
	{
		Object::Print(str);
		str << _color;
	}

	virtual ~Inanimate_Object() = default;

};
 

class Human : public Object
{
protected:

	unsigned short _isMan = not_defined;
	unsigned short _isChildren = not_defined;
	unsigned short _isHaveGlasses = not_defined;
	unsigned short _isHaveBeard = not_defined;

public:

	Human(const unsigned short isMan, const unsigned short isChildren, const unsigned short isHaveGlasses, const unsigned short isHaveBeard, const Position& pos) :Object(pos)
	{
		_isMan = isMan;
		_isChildren = isChildren;
		_isHaveGlasses = isHaveGlasses;
		_isHaveBeard = isHaveBeard;
	}

	Human(Human& other) : Object(other._pos)
	{
		this->_isMan = other._isMan;
		this->_isChildren = other._isChildren;
		this->_isHaveGlasses = other._isHaveGlasses;
		this->_isHaveBeard = other._isHaveBeard;
	}

	friend  std::ostream& operator << (std::ostream& str, const Human& o)
	{
		o.Print(str);
		return str;
	}

	friend std::ofstream operator << (std::ofstream& stream, const Human& obj) {

		stream << "Human" << obj._pos << " " << obj._isChildren << " " << obj._isHaveBeard << " " << obj._isHaveGlasses << " " << obj._isMan;
	}

	void Print(std::ostream& str) const override
	{
		str << "Human ";
		Object::Print(str);

		if (_isMan == Check::yes)
		{
			str << "Man ";
		}
		else if (_isMan == Check::no)
		{
			str << "Woman ";
		}
		else
		{
			str << "Not defined ";
		}

		if (_isChildren == Check::yes)
		{
			str << "Yes ";
		}
		else if (_isChildren == Check::no)
		{
			str << "No ";
		}
		else
		{
			str << "Not defined ";
		}


		if (_isHaveGlasses == Check::yes)
		{
			str << "Yes ";
		}
		else if (_isHaveGlasses == Check::no)
		{
			str << "No ";
		}
		else
		{
			str << "Not defined ";
		}


		if (_isHaveBeard == Check::yes)
		{
			str << "Yes ";
		}
		else if (_isHaveBeard == Check::no)
		{
			str << "No ";
		}
		else
		{
			str << "Not defined ";
		}

		str << endl;
	}

	virtual ~Human() = default;

};



class Cyclist : public Human
{
private:

	char* _bike_color = nullptr;

public:

	Cyclist(const unsigned short isMan, const unsigned short isChildren, const unsigned short isHaveGlasses, const unsigned short isHaveBeard, const Position& pos, char* bike_color) : Human(isMan, isChildren,isHaveGlasses, isHaveBeard, pos)
	{
		_bike_color = bike_color;
	}

	Cyclist(Cyclist& other) : Human(other._isMan, other._isChildren, other._isHaveGlasses, other._isHaveBeard, other._pos)
	{
		this->_bike_color = other._bike_color;
	}

	friend  std::ostream& operator << (std::ostream& str, const Cyclist& o)
	{
		o.Print(str);
		return str;
	}

	friend std::ofstream operator << (std::ofstream& stream, const Cyclist& obj) {

		stream << "Cyclist" << obj._pos << " " << obj._isChildren << " " << obj._isHaveBeard << " " << obj._isHaveGlasses << " " << obj._isMan << " " << obj._bike_color;
	}

	void Print(std::ostream& str) const override
	{
		str << "Cyclist";
		Human::Print(str);
		str << _bike_color << endl;
	}

	virtual ~Cyclist() = default;
};


class Car : public Inanimate_Object
{
private:

	char* _number = nullptr;
	bool _isTaxi = false;

public:

	Car(char* number, bool isTaxi, char* color, const Position& pos) : Inanimate_Object(color, pos)
	{
		_number = number;
		_isTaxi = isTaxi;
	}

	Car(const Car& other) : Inanimate_Object(other._color, other._pos)
	{
		this->_number = other._number;
		this->_isTaxi = other._isTaxi;
	}

	friend  std::ostream& operator << (std::ostream& str, const Car& o)
	{
		o.Print(str);
		return str;
	}

	friend std::ofstream operator << (std::ofstream& stream, const Car& obj) {

		stream << "Car" << obj._pos << " " << obj._color << " " << obj._isTaxi << " " << obj._number;
	}

	void Print(std::ostream& str) const override
	{
		str << "Car ";
		Inanimate_Object::Print(str);
		str << _number;
		if (_isTaxi)
		{
			str << "Yes" << endl;
		}
		else
		{
			str << "No" << endl;
		}
	}

};



class Bag : public Object
{
private:

	char* _time = nullptr;

public:

	Bag(char* time, const Position& pos) : Object(pos)
	{
		_time = time;
	}

	Bag(Bag& other) : Object(other._pos)
	{
		this->_pos = other._pos;
	}

	friend  std::ostream& operator << (std::ostream& str, const Bag& o)
	{
		o.Print(str);
		return str;
	}

	friend std::ofstream operator << (std::ofstream& stream, const Bag& obj) {

		stream << "Bag" << obj._pos << " " << obj._time;
	}

	void Print(std::ostream& str) const override
	{
		str << "Bag ";
		Object::Print(str);
		str << _time << endl;
	}

	virtual ~Bag() = default;

};




//int main()
//{
//	Position p(1, 2, 3, 4);
//
//	Object o(p);
//
//	Human h(yes, no, not_defined, yes, p);
//
//	cout << h << endl;
//
//}