//resource : https://www.luogu.org/problem/show?pid=1216
//data struction : serrated array
//algorithm : dynamic plan
//language : C++
//IDE : Visual Studio 2013
//2016.12.3
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX(_X_, _Y_) (_X_ < _Y_) ? _Y_ : _X_

int main()
{
	int line = 0;
	std::cin >> line;

	int** tow = new int*[line];
	for (int i = 0; i < line; i++)
	{
		tow[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++)
		{
			int n = 0;
			std::cin >> n;
			tow[i][j] = n;
		}
	}

	for (int i = line - 2; i > -1; i--)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int max = MAX(tow[i + 1][j], tow[i + 1][j + 1]);
			tow[i][j] += max;
		}
	}

	std::cout << tow[0][0];

	return 0;
}