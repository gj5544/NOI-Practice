//resouce : https://www.luogu.org/problem/show?pid=1465
//data struct : --
//algorithm : --
//language : C++
//IDE : Visual Studio 2013
//2016.12.5
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

struct RomeNum
{
	int num[7];
};

int count[7] = {0, 0, 0, 0, 0, 0, 0};
char mark[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

std::map<int, RomeNum> map;

inline void init();

void add(RomeNum);

int main()
{
	int num = 0;
	std::cin >> num;

	init();

	for (int i = 1; i <= num; i++)
	{
		int k = i;
		RomeNum rn;

		rn = map[i % 10];
		add(rn);

		i /= 10;
		rn = map[(i % 10) * 10];
		add(rn);

		i /= 10;
		rn = map[(i % 10) * 100];
		add(rn);

		i /= 10;
		rn = map[(i % 10) * 1000];
		add(rn);

		i = k;
	}

	for (int i = 0; i < 7; i++)
	{
		if (count[i] == 0)
		{
			continue;
		}

		std::cout << mark[i] << " " << count[i] << std::endl;
	}

	return 0;
}

void add(RomeNum rn)
{
	for (int i = 0; i < 7; i++)
	{
		count[i] += rn.num[i];
	}
}

inline void init()
{
	RomeNum rn;
	rn.num[0] = 0;
	rn.num[1] = 0;
	rn.num[2] = 0;
	rn.num[3] = 0;
	rn.num[4] = 0;
	rn.num[5] = 0;
	rn.num[6] = 0;
	map[0] = rn;

	rn.num[0] = 1;
	map[1] = rn;
	rn.num[0] = 2;
	map[2] = rn;
	rn.num[0] = 3;
	map[3] = rn;
	rn.num[0] = 1;
	rn.num[1] = 1;
	map[4] = rn;
	rn.num[0] = 0;
	map[5] = rn;
	map[6] = map[4];
	rn.num[0] = 2;
	map[7] = rn;
	rn.num[0] = 3;
	map[8] = rn;
	rn.num[0] = 1;
	rn.num[1] = 0;
	rn.num[2] = 1;
	map[9] = rn;
	rn.num[0] = 0;
	map[10] = rn;

	rn.num[2] = 2;
	map[20] = rn;
	rn.num[2] = 3;
	map[30] = rn;
	rn.num[2] = 1;
	rn.num[3] = 1;
	map[40] = rn;
	rn.num[2] = 0;
	map[50] = rn;
	map[60] = map[40];
	rn.num[2] = 2;
	map[70] = rn;
	rn.num[2] = 3;
	map[80] = rn;
	rn.num[3] = 0;
	rn.num[4] = 1;
	rn.num[2] = 1;
	map[90] = rn;
	rn.num[2] = 0;
	map[100] = rn;

	rn.num[4] = 2;
	map[200] = rn;
	rn.num[4] = 3;
	map[300] = rn;
	rn.num[4] = 1;
	rn.num[5] = 1;
	map[400] = rn;
	rn.num[4] = 0;
	map[500] = rn;
	map[600] = map[400];
	rn.num[4] = 2;
	map[700] = rn;
	rn.num[4] = 3;
	map[800] = rn;
	rn.num[5] = 0;
	rn.num[4] = 1;
	rn.num[6] = 1;
	map[900] = rn;

	rn.num[4] = 0;
	map[1000] = rn;
	rn.num[6] = 2;
	map[2000] = rn;
	rn.num[6] = 3;
	map[3000] = rn;
}