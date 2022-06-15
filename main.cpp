#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List<char> list_1;
    List<char> list_2;

    list_1.Add("Hi, lord!H");
    list_2.Add("Hello world!!!H");


    list_1.Print();
    list_2.Print();

    List<char>* list_3 = Task(list_1, list_2);
    list_3->Print();

    return 0;

}