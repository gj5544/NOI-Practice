//resouce : https://www.luogu.org/problem/show?pid=1551
//data struct : --
//algorithm : Union Find 
//language : C++
//IDE : Visual Studio 2013
//2016.11.10
#include <iostream>
#include <cstdio>
#include <cstdlib>

int* parent = NULL;
int* rank = NULL;

int find(int);

void unionByRank(int, int);

int main()
{
	int count = 0;
	int link = 0;
	int require = 0;
	std::cin >> count >> link >> require;

	parent = new int[count];
	rank = new int[count];
	for (int i = 0; i < count; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	for (int i = 0; i < link; i++)
	{
		int x = 0;
		int y = 0;
		std::cin >> x >> y;

		unionByRank(x - 1, y - 1);
	}

	for (int i = 0; i < require; i++)
	{
		int x = 0;
		int y = 0;
		std::cin >> x >> y;

		if (find(x - 1) == find(y - 1))
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}

	return 0;
}

int find(int x)
{
	int p = parent[x];
	while (p != parent[p])
	{
		p = parent[p];
	}

	int i = x;
	int j = 0;
	while (parent[i] != p)
	{
		j = parent[i];
		parent[i] = p;
		i = j;
	}

	return p;
}

void unionByRank(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if (px == py)
	{
		return;
	}

	if (rank[px] > rank[py])
	{
		parent[py] = px;
	}
	else
	{
		parent[px] = py;

		if (rank[px] == rank[py])
		{
			rank[py]++;
		}
	}
}