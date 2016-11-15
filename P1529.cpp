//resouce : https://www.luogu.org/problem/show?pid=1529
//data struction : queue
//algorithm : SPFA
//language : C++
//IDE : Dev C++
//2016.11.15

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAX 52

struct Edge
{
	int from;
	int to;
	int weight;
};

typedef std::vector<Edge> List;

int fakeHash(char);
char re_fakeHash(int);

int main()
{
	int edge = 0;
	std::cin >> edge;
	
	List map[MAX];
	bool exist[MAX];
	for (int i = 0; i < MAX; i++)
	{
		exist[i] = false;
	}
	
	for (int i = 0; i < edge; i++)
	{
		char f = 0;
		char t = 0;
		int w = 0;
		std::cin >> f >> t >> w;
		
		if (f == t)
		{
			continue;
		}
		
		int hf = fakeHash(f);
		int ht = fakeHash(t);
		
		Edge e;
		e.to = ht;
		e.weight = w;
		map[hf].push_back(e);
		
		e.to = hf;
		map[ht].push_back(e);
		
		if (ht >= 27)
		{
			exist[ht] = true;
		}
		if (hf >= 27)
		{
			exist[hf] = true;
		}
	}
	
	int dist[MAX];
	for (int i = 0; i < MAX; i++)
	{
		dist[i] = 9999999;
	}
	dist[0] = 0;
	
	bool visit[MAX];
	for (int i = 0; i < MAX; i++)
	{
		visit[i] = false;
	}
	visit[0] = true;
	
	std::queue<int> queue;
	queue.push(0);
	
	while (!queue.empty())
	{
		int index = queue.front();
		queue.pop();
		
		int size = map[index].size();
		for (int i = 0; i < size; i++)
		{
			int t = map[index][i].to;
			int d = map[index][i].weight + dist[index];
			
			if (d < dist[t])
			{
				dist[t] = d;
				queue.push(t);
				
				if (!visit[t])
				{
					visit[t] = true;
				}
			}
		}
		
		visit[index] = false;
	}
	
	int min = 99999;
	int pos = 0;
	
	for (int i = 1; i < MAX; i++)
	{
		if (dist[i] < min && exist[i])
		{
			min = dist[i];
			pos = i;
		}
	}
	
	std::cout << re_fakeHash(pos) << " " << min;
	
	return 0;
}

int fakeHash(char c)
{
	if (c == 'Z')
	{
		return 0;
	}
	
	if (c >= 'a')
	{
		return (int)(c - 'a' + 1);
	}
	else
	{
		return (int)(c - 'A' + 27);
	}
}

char re_fakeHash(int i)
{
	if (i == 0)
	{
		return 'Z';
	}
	
	if (i >= 27)
	{
		return (char)(i + 'A' - 27);
	}
	else
	{
		return (char)(i + 'a' - 1);
	}
}
