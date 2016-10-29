//resouce : https://www.luogu.org/problem/show?pid=2661
//data struction : adjacency list, stack
//algorithm : tarjan
//language : C++
//IDE : Visual Studio 2013
//2016.10.29

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

int min = 9999999;
int layer = 1;

int* map = NULL;
int* dfs = NULL;
int* low = NULL;

bool* visit = NULL;

std::stack<int> stack;

void tarjan(int);

int main()
{
	int count = 0;
	std::cin >> count;

	map = new int[count];
	dfs = new int[count];
	low = new int[count];
	visit = new bool[count];

	for (int i = 0; i < count; i++)
	{
		int t = 0;
		std::cin >> t;
		map[i] = t - 1;

		dfs[i] = 0;
		low[i] = 0;
		visit[i] = false;
	}

	for (int i = 0; i < count; i++)
	{
		if (visit[i])
		{
			continue;
		}

		tarjan(i);
	}

	std::cout << min;

	//system("pause");
	return 0;
}

void tarjan(int i)
{
	layer++;

	dfs[i] = layer;
	low[i] = layer;
	visit[i] = true;
	stack.push(i);

	int next = map[i];

	if (!visit[next])
	{
		tarjan(next);

		low[i] = (low[i] > low[next]) ? low[next] : low[i];
	}
	else
	{
		low[i] = (low[i] > dfs[next]) ? dfs[next] : low[i];
	}

	if (dfs[i] == low[i])
	{
		int sum = 0; 

		while (true)
		{
			int k = stack.top();
			stack.pop();

			sum++;
			if (i == k)
			{
				break;
			}
		}

		min = (sum < min && sum > 1) ? sum : min;
	}
}