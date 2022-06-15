#include<iostream>
using namespace std;

class Num
{
	static constexpr size_t _digits = 256U;

	int _arr[_digits] = { 0 };

	friend Num LowestCommonDenominator(Num x, Num y);

	friend ostream& operator <<(ostream& s, const Num& b)
	{
		for (int i = 0; i < 256; i++)
		{
			s << b[i] << " ";
		}
		cout << endl;
		return s;
	}

	friend istream& operator >> (istream& s, Num& c)// перегруженный оператор ввода
	{
		for (int i = 0; i < _digits; i++)
		{
			s >> c[i];
		}
		return s;
	}

public:
	Num() = default;
	Num(int num, int deg = 1)
	{
		if (deg == 0)
		{
			_arr[_digits - 1] = 1;
		}
		else
		{
			int position = 0;
			while (num != 0)
			{
				if (num % 2 == 1)
					_arr[_digits - 1 - position] = 1;
				position++;
				num /= 2;
			}

			Num Buf = *this;
			for (int i = 1; i < deg; i++)
			{
				degree(Buf);
			}
		}
	}

	Num(const Num& A)
	{
		for (int i = 0; i < _digits; i++)
		{
			_arr[i] = A[i];
		}
	}

	Num(Num&& A) noexcept
	{
		for (int i = 0; i < _digits; i++)
		{
			_arr[i] = A[i];
			A[i] = 0;
		}
	}

	~Num() = default;

	Num operator = (const Num& other)
	{
		if (this != &other) {
			for (int i = 0; i < _digits; i++)
			{
				_arr[i] = other[i];
			}
		}
		return *this;
	}

	Num& operator = (Num&& other) noexcept
	{
		if (this != &other) {
			for (int i = 0; i < 256; i++)
			{
				_arr[i] = other._arr[i];
				other._arr[i] = 0;
			}
		}
		return *this;
	}
	//const right //const left
	Num operator +(const Num& b) const
	{
		Num result;
		for (int i = _digits - 1; i >= 0; i--)
		{
			result[i] += _arr[i] + b[i];

			if (result[i] == 2)
			{
				if (i == 0)
					result[i] = 0;
				else
					result[i] = 0;
				result[i - 1] += 1;
			}
			else if (result[i] == 3)
			{
				result[i] = 1;
				result[i - 1] += 1;
			}
		}
		return result;
	}

	Num operator -(const Num& b) const
	{
		Num result;
		for (int i = 255; i >= 0; i--)
		{
			if (_arr[i] < 0)
			{
				result._arr[i] = 1;
				result._arr[i - 1]--;
			}

			result[i] += abs(_arr[i] - b[i]);
			if (_arr[i] == 0 && b[i] == 1)
			{
				result._arr[i - 1]--;
			}
		}
		return result;
	}

	void Shift(int n) // сдвиг на Н разрядов 
		// рлолл
	{
		Num B;
		for (int i = 0; i < _digits - 1; i++)
		{
			if (n + i > _digits)
				break;
			B[n + i] = _arr[i];
		}
		*this = B;
	}

	bool operator >(const Num& A) const
	{
		for (int i = 0; i < _digits; i++)
		{
			if (_arr[i] > A[i])
			{
				return true;
			}
			else if (_arr[i] < A[i])
			{
				return false;
			}
		}
	}

	bool operator <(const Num& A) const
	{
		for (int i = 0; i < _digits; i++)
		{
			if (_arr[i] > A[i])
			{
				return false;
			}
			else if (_arr[i] < A[i])
			{
				return true;
			}
		}
	}

	Num operator %(const Num& B) const
	{
		Num A(*this);

		if (A > B)
		{
			while (A > B)
			{
				A = A - B;
			}
			return A;
		}
		else if (A < B)
		{
			return A;
		}
		else if (A == B)
		{
			Num NUL;
			return NUL;
		}
	}

	bool operator ==(const Num& A) const
	{
		for (int i = 0; i < _digits; i++)
		{
			if (_arr[i] != A[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator != (const Num& A) const
	{
		for (int i = 0; i < 256; i++)
		{
			if (_arr[i] != A[i])
			{
				return true;
			}
		}
		return false;
	}

	int& operator [](int i)
	{
		return _arr[i];
	}

	const int& operator [](int i) const
	{
		return _arr[i];
	}

	void degree(const Num& A)
	{
		Num result;
		int k = 0;

		for (int i = 255; i > 0; i--)
		{
			for (int j = 255; j > 0; j--)
			{
				result[j - k] += _arr[j] * A[i];
				if (result[j - k] == 2)
				{
					result[j - k] = 0;
					result[j - k - 1] += 1;
				}
				else if (result[j - k] == 3)
				{
					result[j - k] = 1;
					result[j - k - 1] += 1;
				}
			}
			k++;
		}
		*this = result;
	}
};

Num LowestCommonDenominator(Num a, Num b)
{
	Num NUL{};
	if (a % b == NUL)
		return b;
	if (b % a == NUL)
		return a;


	return (a > b) ? LowestCommonDenominator(a % b, b) : LowestCommonDenominator(a, b % a);
}


void main()
{
	setlocale(LC_ALL, "");
	Num A(2, 24);
	Num B(2, 6);
	Num C(7);
	Num R1 = A - B + C;
	Num D(2, 10);
	Num E(1);
	Num R2 = D - E;
	cout << LowestCommonDenominator(R1, R2);

}