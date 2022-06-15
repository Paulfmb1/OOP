#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string number;
	cout << "Enter the number: ";
	cin >> number;
    int i = 0;

	float _number = stod(number);

    double Znak = _number;
    double Fractional_part = abs(_number);
    int Whole_part = floor(_number);
    Fractional_part -= Whole_part;

    string result;
    if (Fractional_part != 0.0)
    {
        for (int j = 10; j > 0; j--)
        {
            Fractional_part *= 16;
            int temp = floor(Fractional_part);
            Fractional_part -= temp;

            char _c;
            if (temp >= 10) {
                _c = 'A' + temp - 10;
            }
            else {
                _c = temp + '0';
            }

            result = _c + result;
            i++;
        }
        i++;

        result = result + '.';

    }

    if (Whole_part == 0.0)
    {
        i++;
        result = '0' + result;

    }
    else
    {
        while (Whole_part > 1)
        {
            i++;
            int temp = Whole_part % 16;
            Whole_part /= 16;

            char c;
            if (temp >= 10) {
                c = 'A' + temp - 10;
            }
            else {
                c = temp + '0';
            }

            result = result + c;

        }
    }

   /* for (int j = 0; j < i / 2; j++)
    {
        char temp = result[j];
        result[j] = result[i - j];
        result[i - j] = temp;
    }*/
    std::reverse(result.begin(), result.end());

    if (Znak < 0)
        cout << "Result = -" << result << endl;
    else
        cout << "Result = " << result << endl;
}
