#include <iostream>
#include "aghMatrix.h"

#include "aghException.h"

using namespace std;

int main()
{
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

	macierz.setItems(2, 1, 91, 92);// , 93, 94);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << macierz.getItem(i, j) << "  ";

		cout << "\n";
	}

	getchar();
	return 0;
}