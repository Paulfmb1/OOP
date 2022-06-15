#include <iostream>
#include <list>

using namespace std;

void Fill(list<double>& lst, int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        lst.push_back((rand() % 1000 + 1) / 100.0);
    }
}

void Task(list<double>& lst, int n)
{
    double result = 1.0;

    auto i = lst.begin();
    auto j = lst.rbegin();

    for (int k = 0; k < n; ++i, ++j, k++)
    {
        result *= (*i - *j);
    }

    cout << result << endl;
}

int main()
{
    srand(time(NULL));

    int n;
    cout << "Enter the amount of number: ";
    cin >> n;

    list<double> lst;
    Fill(lst, n);

    Task(lst, n);

    return 0;
}