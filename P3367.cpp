//resouce : https://www.luogu.org/problem/show?pid=3367
//data struct : --
//algorithm : Union Find 
//language : C++
//IDE : Dev C++
//2016.11.10
#include <iostream>
#include <cstdio>
#include <cstdlib>

int* parent = NULL;
int* rank = NULL;

int find(int);

int main()
{
	int it_count = 0;
	int op_count = 0;
	std::cin >> it_count >> op_count;
	
	parent = new int[it_count];
	rank = new int[it_count];
	
	for (int i = 0; i < it_count; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	
	for (int i = 0; i < op_count; i++)
	{
		int op = 0;
		int x = 0;
		int y = 0;
		std::cin >> op >> x >> y;
		
		x--;y--;
		
		if (op == 2)
		{
			if (find(x) == find(y))
			{
				std::cout << "Y" << std::endl;
			}
			else
			{
				std::cout << "N" << std::endl;
			}
		}
		else
		{
			int tx = find(x);
			int ty = find(y);
			
			if (tx != ty)
			{
				if (rank[tx] > rank[ty])
				{
					parent[ty] = tx;
				}
				else
				{
					parent[tx] = ty;	
					
					if (rank[tx] == rank[ty]) 
					{
						rank[ty]++;
					}
				}
			}
		}
	}
	
	return 0;
}

int find(int x)
{
	if (x != parent[x])
	{
		parent[x] = find(parent[x]);
	}
	
	return parent[x];
}
