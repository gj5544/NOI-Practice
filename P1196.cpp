//resouce : https://www.luogu.org/problem/show?pid=1196
//data struct : --
//algorithm : Union Find
//language : C++
//IDE : Dev C++
//2016.12.8

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX 30000

struct Ship
{
	int fparent;
	int parent;
	int dis;
	int len;
};

Ship list[MAX];

int find(int);
inline int getDistance(int);
void unionBySort(int, int);

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		list[i].dis = 0;
		list[i].len = 1;
		list[i].parent = i;
		list[i].fparent = i;
	}

	int count = 0;
	std::cin >> count;

	for (int i = 0; i < count; i++)
	{
		char cmd = 0;
		int head = 0;
		int tail = 0;
		std::cin >> cmd >> tail >> head;
		head--; tail--;

		if (cmd == 'M')
		{
			unionBySort(tail, head);
		}
		else
		{
			if (find(head) == find(tail))
			{
				int sub = getDistance(head) - getDistance(tail);
				sub = (sub < 0) ? -sub : sub;
				std::cout << sub - 1 << std::endl;
			}
			else
			{
				std::cout << "-1" << std::endl;
			}
		}
	}

	return 0;
}

int find(int i)
{
	int p = list[i].parent;

	while (p != list[p].parent)
	{
		p = list[p].parent;
	}
	int j = i;
	int k = 0;

	while (j != p)
	{
		k = list[j].parent;
		list[j].parent = p;
		j = k;
	}

	return p;
}

void unionBySort(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if (px == py)
	{
		return;
	}

	list[px].parent = py;
	list[px].fparent = py;
	list[px].dis = list[py].len;

	if (list[px].len == 1)
	{
		list[py].len++;
	}
	else
	{
		list[py].len += list[px].len;
	}
}

inline int getDistance(int i)
{
	int fp = list[i].fparent;
	int dis = list[i].dis;

	while (fp != list[fp].fparent)
	{
		dis += list[fp].dis;
		fp = list[fp].fparent;
	}
	
	list[i].fparent = fp;
	list[i].dis = dis;

	return dis;
}
