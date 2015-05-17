/**
* \file aghComplex.h
* \author Jakub Brzegowski
* \date 17.05.2015
* \version 1.0
* \Header file with class aghComplex
*/
// -------------------------------------------------------------------------

#include "aghException.h"

#ifndef AGH_COMPLEX
#define AGH_COMPLEX
// -------------------------------------------------------------------------

/**
* \class aghComplex
* \author Jakub Brzegowski
* \date 17.05.2015
* \Class which represent complex numbers
*/

class aghComplex
{
	double re, im;	///< Realis and Pars Imaginaria of complex number
public:
	/// \brief default constructor
	aghComplex() : re(0), im(0) {}

	/// \brief copy constructor
	///
	/// \param other - complex number
	aghComplex(const aghComplex& other) : re(other.re), im(other.im) {}

	/// \brief two-parameter constructor
	///
	/// \param re - Realis part of complex number
	/// \param im - Imaginaria part of complex number
	aghComplex(int re, int im) : re(re), im(im) {}

	/// \brief default destructor
	~aghComplex() {}

	/// \brief overloaded assignment operator
	///
	/// \param other - other complex number
	aghComplex& operator= (const aghComplex& other);

	/// \brief overloaded assignment operator
	///
	/// \param other - integer number treated as Realis part
	aghComplex& operator= (const int& other);

	/// \brief overloaded assignment operator
	///
	/// \param other - other complex number
	aghComplex& operator+= (const aghComplex& other);

	/// \brief overloaded addition operator
	///
	/// \param other - other complex number
	aghComplex operator+ (const aghComplex& other);

	/// \brief overloaded multiplication operator
	///
	/// \param other - other complex number
	aghComplex operator* (const aghComplex& other);

	/// \brief overloaded equality operator
	///
	/// \param other - other complex number
	bool operator== (const aghComplex& other);

	/// \brief overloaded inequality operator
	///
	/// \param other - other complex number
	bool operator!= (const aghComplex& other);

	/// \brief overloaded operator for output stream from sdt library
	///
	/// \param out - output stream
	/// \param number - complex number
	friend ostream& operator<<(ostream& out, const aghComplex& number)
	{
		return out;
	}
};

// -------------------------------------------------------------------------
#endif
