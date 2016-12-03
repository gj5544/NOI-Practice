//resouce : https://www.luogu.org/problem/show?pid=1111
//data struct : --
//algorithm : Union Find, Quick Sort
//language : C++
//IDE : Visual Studio 2013
//2016.12.3
#include <iostream>
#include <cstdio>
#include <cstdlib>

struct Node
{
	int x;
	int y;
	int cost;
};

int* parent = NULL;
int* rank = NULL;

Node* list = NULL;

int cmp(const void*, const void*);

int find(int);
void unionByRank(int, int);

int main()
{
	int vil = 0;
	int road = 0;
	std::cin >> vil >> road;

	parent = new int[vil];
	rank = new int[vil];
	for (int i = 0; i < vil; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	list = new Node[road];
	for (int i = 0; i < road; i++)
	{
		int x = 0;
		int y = 0;
		int c = 0;
		std::cin >> x >> y >> c;

		list[i].cost = c;
		list[i].x = x;
		list[i].y = y;
	}

	qsort(list, road, sizeof(Node), cmp);

	int tt = -1;
	for (int i = 0; i < road; i++)
	{
		unionByRank(list[i].x - 1, list[i].y - 1);
		find(list[i].x - 1);
		find(list[i].y - 1);

		bool flag = true;
		int last = parent[0];
		for (int k = 1; k < vil; k++)
		{
			if (last != find(k))
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			tt = list[i].cost;
			break;
		}
	}

	std::cout << tt;

	return 0;
}

int cmp(const void* a, const void* b)
{
	Node* na = (Node*)a;
	Node* nb = (Node*)b;

	return na->cost - nb->cost;
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