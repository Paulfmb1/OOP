#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;
using namespace Noob;

int main() 
{

    Matrix<int> m(2, 2);
    m.AscendingFill();
    cout << m << endl;


    size_t pow;
    cout << "Enter pow the Matrix: ";
    cin >> pow;
    
    m.Pow(pow);
    cout << m << endl;

    return 0;
}