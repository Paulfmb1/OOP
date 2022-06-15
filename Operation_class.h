#pragma once
#include <iostream>
#include<fstream>

using namespace std;

class String
{
private:
	char* _string = nullptr;
	 
public:

private:

	

public:

	String();
	String(const String& other);
	String(const char ch[]);
	~String();
	void Print();
	void Insert_element(char el, const unsigned int index);
	char Get_element(size_t index);
	void Task(const String& other);
	void Delete_space();

	friend ostream& operator<<(ostream& str, const String& s)
	{
		
		return str << s._string;
	}

	friend istream& operator>>(istream& str, String& s)
	{
		if (!s._string)
			s._string = new char[128]{};

		s._string[0] = '\0';
		str >> s._string;
		return str;
	}
};

