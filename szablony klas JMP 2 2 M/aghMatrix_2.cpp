#include "aghMatrix.h"
#include <iostream>

using namespace std;

aghMatrix<char>& aghMatrix<char>::operator= (const aghMatrix<char>& other)
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

aghMatrix<char> aghMatrix<char>::operator+ (const aghMatrix<char>& other)
{
	if (this->m != other.m || this->n != other.n)
		throw aghException(0, "You can't add two matrices which have different dimensions.", __FILE__, __LINE__);	/// Checking if we can add this two matrices

	aghMatrix<char> newMatrix(this->m, this->n);	/// Creation of new object with dimensions like two other matrices

	int sum = 0; ///< Auxiliary variable

	/** In ASCII table:
	*	a -> 97
	*	z -> 122
	*/
	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
		{
		sum = (this->pointer[i][j] - 97) + (other.pointer[i][j] - 97);	/// Setting values of elements from 'newMatrix' by adding corresponding elements
		newMatrix.pointer[i][j] = sum % 26 + 97;
		}

	return newMatrix;	/// Returning created 'newMatrix'
}

aghMatrix<char> aghMatrix<char>::operator* (const aghMatrix<char>& other)
{
	if (this->n != other.m)
		throw aghException(0, "You can't mulitply two matrices which have different dimensions.", __FILE__, __LINE__);	/// Checking if we can multiply this two matrices

	aghMatrix<char> newMatrix(this->m, other.n);	/// Creation of new object with proper dimensions

	int sum = 0; ///< Auxiliary variable

	/** In ASCII table:
	*	a -> 97
	*	z -> 122
	*/
	for (int i = 0; i < this->m; i++)	/// Setting right row
		for (int j = 0; j < other.n; j++)	/// Setting right column
		{
		for (int k = 0; k < this->n; k++)	/// We multiply k elements, so...
			sum += (this->pointer[i][k] - 97) * (other.pointer[k][j] - 97);	/// Setting values of elements from 'newMatrix' by adding multiplication of corresponding elements

		newMatrix.pointer[i][j] = sum % 26 + 97;
		}

	return newMatrix;	/// Returning created 'newMatrix'
}