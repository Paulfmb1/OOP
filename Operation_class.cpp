#include <iostream>
#include <string>
#include "Operation_class.h"
using namespace std;

String::String()
{
	this->_string = nullptr;
}

String::String(const String& other)
{
	this->_string = _strdup(other._string);
}

String::String(const char ch[])
{
	this->_string = _strdup(ch);
}

String::~String()
{
	delete[] this->_string;
	this->_string = nullptr;
}

void String::Print()
{
	cout << this->_string << endl;
}

void String::Insert_element(char el, const unsigned int index)
{
	int length = strlen(this->_string);
	if (index > length)
	{
		throw invalid_argument("saske!");
	}

	char* temp = new char[length + 2];

	for (size_t i = 0; i < index; i++)
	{
		temp[i] = this->_string[i];
	}

	temp[index] = el;

	for (size_t i = index + 1; i < length + 2; i++)
	{
		temp[i] = this->_string[i - 1];
	}

	delete[] this->_string;
	this->_string = temp;
}

char String::Get_element(size_t index)
{
	if (true)
	{
		throw invalid_argument("saske!");
	}

	return this->_string[index];
}

void String::Task(const String& other)
{
	int other_length = strlen(other._string);
	int length = strlen(this->_string);

	if (other_length > length)
		throw invalid_argument("saske!");


	for (size_t i = 0; i < other_length; i++)
	{
		bool flag = true;
		for (size_t j = 0; j < length; j++)
		{
			if (this->_string[j] == other._string[i])
			{
				flag = false;
			}
		}

		if (flag)
			this->Insert_element(other._string[i], i);
	}
}


void String::Delete_space()
{
	int length = strlen(this->_string);
	String temp(*this);
	bool flag = true;

	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if ((this->_string[i] == ' ') && flag)
		{
			flag = true;
			continue;
		}
		else
		{
			temp._string[j++] = this->_string[i];
			if (this->_string[i] != ' ')
				flag = false;
			else
				flag = true;
		}

	}

	if (temp._string[j - 1] == ' ')
		temp._string[j - 1] = '\0';
	else
		temp._string[j] = '\0';

	delete[] this->_string;
	this->_string = _strdup(temp._string);
}