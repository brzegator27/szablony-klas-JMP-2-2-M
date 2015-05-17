/**
* \file aghMatrix.h
* \author Jakub Brzegowski
* \date 16.05.2015
* \version 1.0
* \Header file with class aghMatrix
*/
// -------------------------------------------------------------------------

#include "aghException.h"
#include "aghComplex.h"
#include <stdarg.h>	/// Library essentinal for funtion with unknown number of parameters

#ifndef AGH_MATRIX
#define AGH_MATRIX
// -------------------------------------------------------------------------

/**
* \class aghMatrix
* \author Jakub Brzegowski
* \date 16.05.2015
* \Class which represent matrix
*/

template <class T>
class aghMatrix
{
	T** pointer;	///< pointer to table containing respective fields of matrix
	int m, n;		///< two integers with matrix size

	/// \brief function allocating memory for tables representing matrix
	///
	/// \param m - number of rows
	/// \param n - number of columns
	void allocateMem(int m, int n);

	/// \brief function deallocating memory from tables representing matrix
	void deallocateMem();
public:
	/// \brief default constructor
	aghMatrix();

	/// \brief two-parameter constructor
	///
	/// \param m - number of rows
	/// \param n - number of columns
	aghMatrix(int m, int n);

	/// \brief copy constructor
	///
	/// \param matrix - matrix, which is a model during creation 'this' matrix
	aghMatrix(const aghMatrix& matrix);

	/// \brief default destructor
	~aghMatrix();

	/// \brief overloaded assignment operator 
	///
	/// \param other - other matrix
	aghMatrix<T>& operator= (const aghMatrix<T>& other);

	/// \brief overloaded addition operator 
	///
	/// \param other - other matrix
	aghMatrix<T> operator+ (const aghMatrix<T>& other);

	/// \brief overloaded multiplication operator 
	///
	/// \param other - other matrix
	aghMatrix<T> operator* (const aghMatrix<T>& other);

	/// \brief overloaded equality == operator 
	///
	/// \param other - other matrix
	bool operator== (const aghMatrix<T>& other);

	/// \brief overloaded unequality != operator 
	///
	/// \param other - other matrix
	bool operator!= (const aghMatrix<T>& other);

	/// \brief overloaded function call () operator 
	///
	/// \param m - number of row
	/// \param n - number of column
	T& operator() (int m, int n);

	/// \brief function setting value of element of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	/// \param newValue - new value which we are going to set for matrix
	void setItem(int m, int n, T newValue);

	/// \brief function setting values of each element of matrix; values are taken from one-row table
	///
	/// \param tab - pointer to one-row table with values which we are going to set for matrix's elements
	void setItems(T* tab);

	/// \brief function setting values of some elements of matrix; values are passed as arguments
	///
	/// \param n_args - number of arguments
	/// 1st m - numbers of rows in passing matrix
	/// 2nd n - numbers of columns in passing matrix
	/// 3rd and successive ... - elements of passing matrix
	void setItems(int m, int n, ...);

	/// \brief function getting value of element of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	T getItem(int m, int n);

	inline void write()
	{
		cout << endl;

		for (int i = 0; i < this->m; i++)
		{
			for (int j = 0; j < this->n; j++)
				cout << getItem(i, j) << "  ";

			cout << "\n";
		}
	}
};

// -------------------------------------------------------------------------
#endif





