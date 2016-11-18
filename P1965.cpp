//resouce : https://www.luogu.org/problem/show?pid=1965
//data struct : --
//algorithm : fast power
//language : C++
//IDE : Visual Studio 2013
//2016.11.18

#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef long long lint;

inline lint getLeastCommonMultiple(int, int);
lint getFastPower_10(lint, int);

int main()
{
	int count = 0;
	int dis = 0;
	int target = 0;
	lint circ = 0;
	std::cin >> count >> dis >> circ >> target;

	lint lcm = getLeastCommonMultiple(count, dis);
	circ = getFastPower_10(circ, count);
	circ %= lcm;

	for (lint i = 0; i < circ; i++)
	{
		target += dis;
		target %= count;
	}

	std::cout << target;

	//system("pause");
	return 0;
}

inline lint getLeastCommonMultiple(int x, int y)
{
	if (x % y == 0)
	{
		return x;
	}
	else if (y % x == 0)
	{
		return y;
	}
	else
	{
		int min = (x > y) ? y : x;

		for (int i = 2; i < min; i++)
		{
			if (x % i == 0 && y % i == 0)
			{
				x /= i;
				y /= i;
			}
		}

		return x * y;
	}
}

lint getFastPower_10(lint i, int max)
{
	lint res = 1;
	lint base = 10;

	while (i > 0)
	{
		if (i % 2 != 0)
		{
			res = (res * base) % max;
		}
		base = base * base;
		base %= max;

		i /= 2;
	}

	return res;
}