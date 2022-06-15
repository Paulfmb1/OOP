#include <iostream>
#include <vector>

using namespace std;

void Random_Initialization(vector<double>& Matrix, int size)
{
	for (size_t i = 0; i < size * size; i++)
	{
		Matrix.push_back(rand() % 6);
	}
}

void Print_vector(vector<double>& Matrix, int size)
{
	for (size_t i = 0; i < size * size; i++)
	{
		cout << Matrix[i] << " ";
		if ((i != 0) && ((i + 1) % size == 0))
			cout << endl;
	}
}


void Exponentiation(const vector<double>& Matrix, int size, int degree)
{
	vector<double> result(size * size);
	vector<double> temp(Matrix);

	if (degree == 1)
		result = Matrix;

	while (degree != 1)
	{

		for (int i = 0; i < size * size; i++)
		{
			int temp_2 = 0;

			int COL = i % size;
			int ROW = i / size;

			for (int j = 0; j < size; j++)
			{
				temp_2 += temp[size * ROW + j] * Matrix[j * size + COL];
			}

			result[i] = temp_2;
		}

		temp = result;
		degree--;
	}

	Print_vector(result, size);
}

int main()
{
	srand(time(NULL));

	int size = 0;

	cout << "Enter size of matrix: ";
	cin >> size;

	vector<double> Matrix;

	int degree;
	cout << "Input degree of matrix: ";

	cin >> degree;

	Random_Initialization(Matrix, size);
	Print_vector(Matrix, size);

	cout << endl;
	cout << "---------------------------------" << endl;

	Exponentiation(Matrix, size, degree);

	return 0;
}