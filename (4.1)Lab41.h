#pragma once


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Check
{
	yes,
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

	Position(ifstream& stream)
	{
		stream >> (*this);
	}

	Position(const Position& other) = default;
	Position(Position&& other) = default;
	Position& operator=(const Position& other) = default;
	Position& operator=(Position&& other) = default;

	virtual ~Position() = default;

	double Get_Xmin() const { return _Xmin; }
	double Get_Xmax() const { return _Xmax; }
	double Get_Ymin() const { return _Ymin; }
	double Get_Ymax() const { return _Ymax; }

	
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
		str << "Xmin = " << p.Get_Xmin() << "\tXmax = " << p.Get_Xmax() << "\nYmin = " << p.Get_Ymin() << "\tYmax = " << p.Get_Ymax() << endl;
		return str;
	}

	friend std::istream& operator>>(std::istream& str, Position& p)
	{
		str >> p._Xmin;
		str >> p._Xmax;
		str >> p._Ymin;
		str >> p._Ymax; 
		return str;
	}


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
	
	Object(Object&& other)
	{
		this->_pos = other._pos;
	}

	string GetType() const { return "Object"; }

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
	}


	friend std::ostream& operator << (std::ostream& str, const Object& o) 
	{
		str << o.GetType();
		o.Print(str);
		return str;
	}

	virtual ~Object() = default;

protected:

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

	string _color = " ";

public:

	Inanimate_Object(string color, const Position& pos) : Object(pos)
	{
		this->_color = color;
	}

	Inanimate_Object(Inanimate_Object& other) : Object(other._pos)
	{                          
		this->_color = other._color;
	}

	void Print(std:: ostream& str) const override
	{
		Object::Print(str);
		str << _color << endl;
	}

	virtual ~Inanimate_Object() = default;

	//getset
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

	Human(const Human& other) : Object(other)
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

	void Print(std::ostream& str) const override
	{
		Object::Print(str);

		str << "Gender: ";
		if (_isMan == Check::yes)
		{
			str << "Man" << endl;
		}
		else if (_isMan == Check::no)
		{
			str << "Woman" << endl;
		}
		else
		{
			str << "Not defined" << endl;
		}

		str << "Is children?: ";
		if (_isChildren == Check::yes)
		{
			str << "Yes" << endl;
		}
		else if (_isChildren == Check::no)
		{
			str << "No" << endl;
		}
		else
		{
			str << "Not defined" << endl;
		}

		str << "Is have glasses?: ";
		if (_isHaveGlasses == Check::yes)
		{
			str << "Yes" << endl;
		}
		else if (_isHaveGlasses == Check::no)
		{
			str << "No" << endl;
		}
		else
		{
			str << "Not defined" << endl;
		}

		str << "Is have beard?: ";
		if (_isHaveBeard == Check::yes)
		{
			str << "Yes" << endl;
		}
		else if (_isHaveBeard == Check::no)
		{
			str << "No" << endl;
		}
		else
		{
			str << "Not defined" << endl;
		}
	}

	virtual ~Human() = default;


	//getset
};



class Cyclist : public Human
{
private:

	string _bike_color = " ";

public:

	Cyclist(const unsigned short isMan, const unsigned short isChildren, const unsigned short isHaveGlasses, const unsigned short isHaveBeard, const Position& pos, string bike_color) : Human(isMan, isChildren,isHaveGlasses, isHaveBeard, pos)
	{
		_bike_color = bike_color;
	}

	Cyclist(Cyclist& other) : Human(other)
	{
		this->_bike_color = other._bike_color;
	}

	void Print(std::ostream& str) const override
	{
		Human::Print(str);
		str << "Bike color: " << _bike_color << endl;
	}

	virtual ~Cyclist() = default;
};


class Car : public Inanimate_Object
{
private:

	string _number = " ";
	bool _isTaxi = false;

public:

	Car(string number, bool isTaxi, string color, const Position& pos) : Inanimate_Object(color, pos)
	{
		_number = number;
		_isTaxi = isTaxi;
	}

	Car(const Car& other) : Inanimate_Object(other._color, other._pos)
	{
		this->_number = other._number;
		this->_isTaxi = other._isTaxi;
	}


	void Print(std::ostream& str) const override
	{
		Inanimate_Object::Print(str);
		str << "Number: " << _number << endl;
		str << "Is taxi?: ";
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

	string _time = " ";

public:

	Bag(string time, const Position& pos) : Object(pos)
	{
		_time = time;
	}

	Bag(Bag& other) : Object(other._pos)
	{
		this->_pos = other._pos;
	}

	void Print(std::ostream& str) const override
	{
		Object::Print(str);
		str << "The time when it was first seen: " << _time << endl;
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
