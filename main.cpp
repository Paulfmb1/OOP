#include <iostream>
#include "class.h"
#include <fstream>

using namespace std;

int main()
{
    ofstream out;
    out.open("result.txt");

    if (out.is_open())
    {
        for (int i = 0; i < 20000; i++)
        {
            out << rand() % 10000 + 1 << endl;
        }
    }

    ifstream in("result.txt");

    int k = 0;
    Vector<int> _vector(10001);
    _vector.set_size(10001);
    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            _vector[k]++;
        }
    }
    in.close();

    Vector<int> _vector2(10001);
    _vector2.set_size(10001);
    for (int i = 0, j = 0; i < 10001; i++)
    {
        if (_vector[i] > 1)
        {
            _vector2[j++] = i;
            cout << i << "\n";
        }

    }

    return 0;
}