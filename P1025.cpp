//resouce : https://www.luogu.org/problem/show?pid=1025
//data struct : --
//algorithm : recursion 
//language : C++
//IDE : Visual Studio 2013
//2016.11.19

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

int count = 0;

int max = 0;

void find(int, int);

int main()
{
	int num = 0;
	int part = 0;
	std::cin >> num >> part;

	max = 1;

	find(num, part);

	std::cout << count;

	return 0;
}

void find(int num, int last)
{
	if (last == 1 && num >= max)
	{
		count++;
		return;
	}

	for (int i = max; i < num; i++)
	{
		int cp = max;

		max = i;
		find(num - i, last - 1);
		max = cp;
	}
}