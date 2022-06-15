#include <iostream>
#include <string>
#include "Operation_class.h"

using namespace std;

int main()
{
	String s("   yrr   ob ;wf ihng   ");
	s.Delete_space();
	String ss("123");
	//s.Print(); 
	//s.Insert_element('3', 4);
    s.Task(ss);

	String sss(ss);
	cin >> sss;
	cout << sss;
	cout << endl;
	cout << s;

	return 0;
}