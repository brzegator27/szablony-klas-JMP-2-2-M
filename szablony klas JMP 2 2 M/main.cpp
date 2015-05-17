#include <iostream>
#include "aghMatrix.h"
#include "aghComplex.h"

#include "aghException.h"

using namespace std;

void showTestResult(int _ti, bool _r)
{
	if (_r)
		cout << "Test" << _ti << " PASSED\n";
	else
		cout << "Test" << _ti << " FAILED\n";
}

int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////





	cout << "main by kk. Last updated 20.09.2011\n";

	///////////////////////////////////////////////////////

	int it1[] = { 84, 23, 84, 21, 120, 93, -131, 238 };
	int it2[] = { 249, 24, 82, 3 };
	int it3[] = { 439, 828, 39, 230, 95, 1, -242, 34 };

	aghMatrix<int>* imptr1 = new aghMatrix<int>(2, 4);
	aghMatrix<int>* imptr2 = new aghMatrix<int>(4, 1);
	aghMatrix<int>* imptr3 = new aghMatrix<int>(4, 1);
	aghMatrix<int>* imptr4 = new aghMatrix<int>(2, 4);
	aghMatrix<int> imtest1, imtest2, imtest3;

	imtest1.setItems(4, 1, 249, 24, 82, 3);
	imtest2.setItems(2, 4, 500 + 23, 851, 123, 251, 215, 94, -373, 272);
	imtest3.setItems(2, 1, 28419, 22084);


	aghMatrix<int>& imref1 = *imptr1;
	aghMatrix<int>& imref2 = *imptr2;
	aghMatrix<int>& imref3 = *imptr3;
	aghMatrix<int>& imref4 = *imptr4;

	imptr1->setItems(it1);
	imptr2->setItems(it2);
	imref3 = imref2;
	imptr4->setItems(it3);

	// 1st test - operator przypisania
	showTestResult(1, imref3 == imtest1);

	// 2nd test - operator przypisania
	try
	{
		imref3 = imref3;
		showTestResult(2, imref3 == imref2);
	}
	catch (...)
	{
		showTestResult(2, false);
	}

	// 3rd test - jawne wywolanie destruktora
	imref2.~aghMatrix();
	try
	{
		showTestResult(3, imref3 != imref2);
	}
	catch (...)
	{
		showTestResult(3, false);
	}

	// 4th test - destruktor
	try
	{
		delete imptr2;
		showTestResult(4, true);
	}
	catch (...)
	{
		showTestResult(4, false);
	}

	// 5th test - kopiowanie wartosci
	showTestResult(5, imref3 == imtest1);

	// 6th test - operator dodawania
	try
	{
		showTestResult(6, (imref1 + imref4) == imtest2);
	}
	catch (...)
	{
		showTestResult(6, false);
	}

	// 7th test - operator mno¿enia
	aghMatrix<int> immulres;
	try
	{
		aghMatrix<int> immultmp = imref1*imref3;
		immulres = immultmp;
	}
	catch (...)
	{
		showTestResult(7, false);
	}
	showTestResult(7, immulres == imtest3);

	// 8th test - range test
	try
	{
		immulres(10, 11);
		immulres(10, -11);
	}
	catch (aghException& e)
	{
		showTestResult(8, true);
	}
	catch (...)
	{
		showTestResult(8, false);
	}

	// 9th test - dimesion test
	try
	{
		imref1 + imref3;
	}
	catch (aghException& e)
	{
		showTestResult(9, true);
	}
	catch (...)
	{
		showTestResult(9, false);
	}

	// 10th test - dimesion test
	try
	{
		imref1*imref4;
	}
	catch (aghException& e)
	{
		showTestResult(10, true);
	}
	catch (...)
	{
		showTestResult(10, false);
	}
	/////////////////////////////////////////////////////

	char ct[] = { 'b', 'k', 'l', 'd', 'h', 'z', 'd', 'j', 'z', 'x', 'c', 'n', 'b', 'k', 'z', 'd', 'w' };
	aghMatrix<char> cm1(3, 2);
	aghMatrix<char> cm2(3, 2);
	aghMatrix<char> cm3(2, 4);
	cm1.setItems(ct);
	cm2.setItems(ct + 5);
	cm3.setItems(ct + 8);

	aghMatrix<char> cmtest1, cmtest2;
	cmtest1.setItems(3, 2, 'a', 'n', 'u', 'c', 'e', 'b');
	cmtest2.setItems(3, 4, 'j', 't', 's', 'r', 's', 'x', 't', 'w', 's', 'v', 'p', 'k');

	// 11th test - operator dodawania
	try
	{
		showTestResult(11, (cm1 + cm2) == cmtest1);
	}
	catch (...)
	{
		showTestResult(11, false);
	}

	// 12th test - operator mno¿enia
	try
	{
		cmtest2.write();
		cm1.write();
		cm3.write();
		(cm1*cm3).write();
		showTestResult(12, (cm1*cm3) == cmtest2);
	}
	catch (...)
	{
		showTestResult(12, false);
	}
	/////////////////////////////////////////////////////




	aghComplex cmplxt1[] = { aghComplex(1, 1), aghComplex(1, 2), aghComplex(2, 1), aghComplex(2, 2), aghComplex(3, 3), aghComplex(3, 1), aghComplex(1, 0), aghComplex(0, 1) };
	aghComplex cmplxt2[] = { aghComplex(-1, 2), aghComplex(0, 3), aghComplex(2, 6), aghComplex(3, 2), aghComplex(3, 4) };
	aghMatrix<aghComplex> cmplxm1(3, 2);
	aghMatrix<aghComplex> cmplxm2(2, 1);
	aghMatrix<aghComplex> cmplxm3(2, 1);
	aghMatrix<aghComplex> cmplxm4(2, 1);
	aghMatrix<aghComplex> cmplxmtest1(3, 1);
	aghMatrix<aghComplex> cmplxmtest2(2, 1);

	cmplxm1.setItems(cmplxt1);
	cmplxm2.setItems(cmplxt1 + 6);
	cmplxm3.setItems(cmplxt1 + 3);

	cmplxmtest1.setItems(cmplxt2);
	cmplxmtest2.setItems(cmplxt2 + 3);
	cmplxm4 = cmplxm2 + cmplxm3;

	// 20th test - operator dodawania
	try
	{
		showTestResult(20, cmplxm4 == cmplxmtest2);
	}
	catch (...)
	{
		showTestResult(20, false);
	}

	// 21th test - operator mnozenia
	try
	{
		showTestResult(21, (cmplxm1*cmplxm2) == cmplxmtest1);
	}
	catch (...)
	{
		showTestResult(21, false);
	}
	/////////////////////////////////////////////////////

	cout << "Finally, this is the end...\n";



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	aghMatrix<int> macierz(3,3);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			macierz.setItem(i, j, (i+1)*(j+1));

	macierz.setItem(1, 1, 12);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << macierz.getItem(i, j) << "  ";

		cout << "\n";
	}

	cout << endl;

	aghMatrix<int> macierz2 = macierz;

	macierz2 = macierz2;

	macierz2(0, 0) = 123;

	/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << macierz2.getItem(i, j) << "  ";

		cout << "\n";
	}

	cout << endl;
	*/

	//
	//macierz.setItems(2, 1, 91, 92);// , 93, 94);

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//		cout << macierz.getItem(i, j) << "  ";

	//	cout << "\n";
	//}

	aghMatrix<char> proba1(1, 1);
	proba1(0, 0) = 'a';

	aghMatrix<char> proba2(1, 1);
	proba2(0, 0) = 'b';

	proba2 = proba1 * proba2;

	cout << endl << proba2(0, 0);

	/*
	aghMatrix<aghComplex> complexM_1(1,1);

	aghComplex c1(1, 1);
	aghComplex c2(0, 0);

	complexM_1.setItem(0, 0, c1);
	*/

	getchar();
	return 0;
}