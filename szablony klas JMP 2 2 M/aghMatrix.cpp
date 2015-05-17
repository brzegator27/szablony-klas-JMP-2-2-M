/**
* \file aghMatrix.cpp
* \author Jakub Brzegowski
* \date 16.05.2015
* \version 1.0
* \Header file with class' functions from class aghMatrix
*/
// -------------------------------------------------------------------------


#include "aghMatrix.h"
#include <iostream>

using namespace std;


template class aghMatrix<int>;	/** Written in order to have templates of class' functions in .cpp file
								*	More on: https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
								*/
				

template <class T>
void aghMatrix<T>::allocateMem(int m, int n)
{
	this->pointer = new T*[m];	/// Creation of table for pointers to tables with rows' values

	for (int i = 0; i < m; i++)
		this->pointer[i] = new T[n];	/// Allocation of memory for tables representing each row

	this->m = m;	/// Setting filed in aghMatrix object in order to know how many rows we have created
	this->n = m;	/// Setting filed in aghMatrix object in order to know how many columns we have created

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			this->pointer[i][j] = 0;	/// By Default values are set to 0
}

template <class T>
void aghMatrix<T>::deallocateMem()
{
	if (this->m > 0 || this->n > 0)		/// Checking wheather we have something to delete or not
	{

		for (int i = 1; i < this->m; i++)
			delete[] this->pointer[i];	/// We deallocate memory of tables in which are values from rows

		delete[] this->pointer;		/// Deletion of table with pointers to tables with rows' values

		this->m = 0;	/// Setting number of rows in object's matrix to 0 because now we don't have any
		this->n = 0;	/// Setting number of columns in object's matrix to 0 because now we don't have any
	}
}
	
template <class T>
aghMatrix<T>::aghMatrix()
{
	this->pointer = NULL;	/// Setting pointer to NULL because there is no matrix 
	this->m = 0;	/// Setting number of rows in object's matrix to 0 because now we don't have any
	this->n = 0;	/// Setting number of columns in object's matrix to 0 because now we don't have any
}

template <class T>
aghMatrix<T>::aghMatrix(int m, int n)
{
	allocateMem(m, n);	/// Allocatioin of memory for matrix
}

template <class T>
aghMatrix<T>::aghMatrix(const aghMatrix& matrix)
{
	deallocateMem();	/// Deallocation of memory 

	allocateMem(matrix.m, matrix.n);	/// We allocate as much of new memory, as is in passed 'matrix'

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			this->pointer[i][j] = matrix.pointer[i][j];	/// Copying values from 'matrix' to our object
}

template <class T>
aghMatrix<T>::~aghMatrix()
{
	deallocateMem();	/// Aeallocation of memory from matrix
}

template <class T>
aghMatrix<T>& aghMatrix<T>::operator= (const aghMatrix<T>& other)
{
	if (this != &other)	/// In case where the same object would be assigned to itself
	{
		deallocateMem();	/// Deallocation of memory 

		allocateMem(other.m, other.n);	/// We allocate as much of new memory, as is in passed 'matrix'

		for (int i = 0; i < this->m; i++)
			for (int j = 0; j < this->n; j++)
				this->pointer[i][j] = other.pointer[i][j];	/// Copying values from 'matrix' to our object
	}

	return *this;	/// Returning pointer to 'this' object
}

template <class T>
aghMatrix<T> aghMatrix<T>::operator+ (const aghMatrix<T>& other)
{
	if (this->m != other.m || this->n != other.n)
		throw aghException(0, "You can't add two matrices which have different dimensions.", __FILE__, __LINE__);	/// Checking if we can add this two matrices

	aghMatrix<T> newMatrix(this->m, this->n);	/// Creation of new object with dimensions like two other matrices

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			newMatrix.pointer[i][j] = this->pointer[i][j] + other.pointer[i][j];	/// Setting values of elements from 'newMatrix' by adding corresponding elements

	return newMatrix;	/// Returning created 'newMatrix'
}

template <class T>
aghMatrix<T> aghMatrix<T>::operator* (const aghMatrix<T>& other)
{
	if (this->n != other.m)
		throw aghException(0, "You can't add two matrices which have different dimensions.", __FILE__, __LINE__);	/// Checking if we can multiply this two matrices

	aghMatrix<T> newMatrix(this->m, other.n);	/// Creation of new object with proper dimensions

	for (int i = 0; i < this->m; i++)	/// Setting right row
		for (int j = 0; j < other.n; j++)	/// Setting right column
			for (int k = 0; k < this->n; k++)	/// We multiply k elements, so...
				newMatrix.pointer[i][j] += this->pointer[i][k] * other.pointer[k][j];	/// Setting values of elements from 'newMatrix' by adding multiplication of corresponding elements

	return newMatrix;	/// Returning created 'newMatrix'
}

template <class T>
bool aghMatrix<T>::operator== (const aghMatrix& other)
{
	if (this->m != other.m || this->n != other.n) return false;	/// Matrices should have the same dimensions

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			if (this->pointer[i][j] != other.pointer[i][j]) return false;	/// Matrices should have the same values of corresponding elements

	return true;	/// If both above conditions are fulfiled returned value is 'true'
}

template <class T>
bool aghMatrix<T>::operator!= (const aghMatrix& other)
{
	if (this->m != other.m || this->n != other.n) return true;	/// Matrices might have the other dimensions

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			if (this->pointer[i][j] != other.pointer[i][j]) return true;	/// Matrices might have other values of corresponding elements

	return false;	/// If none of above conditions are fulfiled returned value is 'false'
}

template <class T>
T& aghMatrix<T>::operator() (int m, int n)
{
	return (this->pointer[m][n]);	/// Returning reference to particular element
}

template <class T>
void aghMatrix<T>::setItem(int m, int n, T newValue)
{
	if (m > this->m || n > this->n || m < 0 || n < 0)
		throw aghException(0, "Index out of range", __FILE__, __LINE__);	/// If somebody would like to set value, which is out of range of matrix, then we throw exception

	this->pointer[m][n] = newValue;	/// Setting value of particular element of matrix
}

template <class T>
T aghMatrix<T>::getItem(int m, int n)
{
	if (m > this->m || n > this->n || m < 0 || n < 0)
		throw aghException(0, "Index out of range", __FILE__, __LINE__);	/// If somebody would like to get value, which is out of range of matrix, then we throw exception

	return this->pointer[m][n];	/// Returning value of particular element of matrix
}

template <class T>
void aghMatrix<T>::setItems(T* tab)
{
	/// We assume passing table has as many elements as (m * n)

	int flag = 0; ///< Point to current element in table; current means this, which we are going to write in near future

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			this->pointer[i][j] = tab[flag];	/// Assignment of passed values to object's matrix
			flag++;		/// Guide us through passed table
		}
}

template <class T>
void aghMatrix<T>::setItems(int m, int n, ...)
{
	/** There are only set these elements which overlap
	*	For example: when we try to set elements from matrix 2 x 2
	*	by elements from matrix 4 x 1
	*	There will be set only elements: 1:1, 2:1
	*	Warning! We count starting from 1
	*/

	T* passedMatrix = new T[m*n];	///< Table for passed matrix's elements
	int m_min = 0;	///< Variable which tells us how many rows we can change -> Look at above description of function
	int n_min = 0;	///< Variable which tells us how many columns we can change -> Look at above description of function
	int numberOPE = m * n;	///< number Of Passed Elements
	int flag = 0;	///< Auxiliary variable 

	if (m < this->m) m_min = m;	/// Setting value of m_min
	else m_min = this->m;	

	if (n < this->n) n_min = n;	/// Setting value of n_min
	else n_min = this->n;

	va_list ap;	///< Iterator of arguments
	va_start(ap, m);	/// Starts iterating arguments with a
	va_arg(ap, T);	/// Skipping 2nd argument, which is n, and we don't need to take it once more

	for (int i = 0; numberOPE > 0; numberOPE--)	/// Function read as many arguments as there were passed
	{
		passedMatrix[flag * n + (i % n)] = va_arg(ap, T);	/// Passed arguments are entered into table, which we treat as two-dimension table
		if ((i + 1) % n == 0) flag++;	/// We increase flag so we can move to next, fake row
		i++;	/// Incrementing i variable in order to know how many arguments we have already taken
	}

	va_end(ap); /// This frees va_list list

	for (int i = 0; i < m_min; i++)
		for (int j = 0; j < n_min; j++)
		{
			this->pointer[i][j] = passedMatrix[i * n + j];	/// We change values of elemets in object's matrix which overlap
		}

	delete[] passedMatrix;	/// Deallocating memory
}

