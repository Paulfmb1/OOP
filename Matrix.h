#pragma once

#include "Vector.h"
#include <string>

namespace Noob
{
	using namespace std;

	template <class T>

	class Matrix
	{
	private:

		Vector<Vector<T>> _matrix;
		string _name;
		size_t _rows;
		size_t _cols;

		static size_t counter;

	private:

		void SetName()
		{
			_name = "Matrix" + to_string(++counter);
		}

		void IndexValidation(size_t index) const
		{
			if (index >= _rows)
				throw invalid_argument("Invalid index!");
		}

	public:

		Matrix() { SetName(); }

		Matrix(const size_t rows, const size_t cols) 
		{
			SetName();

			_matrix = Vector<Vector<T>>(rows);
			for (size_t i = 0; i < rows; i++)
				_matrix[i] = Vector<T>(cols);

			_rows = rows;
			_cols = cols;
		}

		Matrix(const Matrix& other)
		{
			SetName();
			_cols = other._cols;
			_rows = other._rows;
			_matrix = other._matrix;
		}
		
		Matrix& operator= (const Matrix& matrix)
		{
			if (this != &matrix) {

				_matrix = matrix._matrix;
				_rows = matrix._rows;
				_cols = matrix._cols;
			}
			return *this;
		}

		Matrix(Matrix&& other)
		{
			SetName();

			_matrix = std::move(_matrix);
			swap(_cols, other._cols);
			swap(_rows, other._rows);
		}

		Matrix<T>& operator=(Matrix<T>&& other)
		{
			if (*this != other)
			{
				_matrix = std::move(_matrix);
				swap(_cols, other._cols);
				swap(_rows, other._rows);
			}
			
			return *this;
		}

		 size_t GetRows() const { return _rows; }

		 size_t GetCols() const { return _cols; }

		 string GetName() const { return _name; }


		 void SetRows(const size_t rows)
		 {
			 _matrix.set_size(rows);
			 if (rows > _rows)
				 for (size_t i = _rows; i < rows; i++)
					 _matrix[i] = vector<T>(_cols);
			 _rows = rows;
		 }

		 void SetCols(const size_t& cols)
		 {
			 for (auto col : _matrix)
				 col.SetSize(cols);

			 _cols = cols;
		 }

		 Vector<T>& operator[](const size_t row) 
		 {
			 IndexValidation(row);
			 return _matrix[row];
		 }

		 const Vector<T>& operator[] (const size_t row) const
		 {
			 IndexValidation(row);
			 return _matrix[row];
		 }


		 friend ostream& operator<< (ostream& os, Matrix& matrix) 
		 {
			 os << matrix.GetName() << endl;
			 for (size_t i = 0; i < matrix.GetRows(); i++) {
				 for (size_t j = 0; j < matrix.GetCols(); j++)
					 os << matrix[i][j] << " ";

				 os << endl;
			 }

			 return os;
		 }

		 void AscendingFill() 
		 {
			 size_t counter = 0;
			 for (size_t i = 0; i < _rows; i++) 
			 {
				 for (size_t j = 0; j < _cols; j++) 
				 {
					 _matrix[i][j] = counter;
					 ++counter;
				 }
			 }
		 }

		 Matrix Pow(const size_t pow) const
		 {
			 if (_cols != _rows)
				 throw runtime_error("Rows and cols must be equals!");

			 Matrix<T> temp(_rows, _cols);
			 temp = *this;
			 Matrix<T> result(_rows, _cols);
			
			 if (pow == 1)
				 return result;

			 for (size_t f = 0; f < pow - 1; f++)
			 {
				 for (size_t i = 0; i < _cols; i++)
				 {
					 for (size_t j = 0; j < _rows; j++)
					 {
						 int tmp = 0;
						 for (size_t k = 0; k < _cols; k++)
						 {
							 tmp += _matrix[i][k] * temp[k][j]; 
						 }
						 result[i][j] = tmp;

					 }
					
				 }
				 temp = result;

			 }

			 return result;
			 
		 }
	};

	template<typename T>
	size_t Matrix<T>::counter = 0;
}

