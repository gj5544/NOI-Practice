//resouce : https://www.luogu.org/problem/show?pid=11359
//data struction : priority_queue
//algorithm : Dijkstra
//language : C++
//IDE : Dev C++
//2016.11.15

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

struct Node
{
	int index;
	int weight;
};

struct Cmp
{
	bool operator() (const Node& n1, const Node& n2)
	{
		return n1.weight > n2.weight;
	}
};

int main()
{
	int count = 0;
	std::cin >> count;
	
	int** map = new int*[count];
	for (int i = 0; i < count; i++)
	{
		map[i] = new int[count];
		for (int j = 0; j < count; j++)
		{
			map[i][j] = 0;
		}
	}
	
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			int d = 0;
			std::cin >> d;
			
			map[i][j] = d; 
		}
	}
	
	bool* visit = new bool[count];
	int* dist = new int[count];
	for (int i = 0; i < count; i++)
	{
		visit[i] = false;
		dist[i] = 999999;
	}
	
	dist[0] = 0;
	
	std::priority_queue<Node, std::vector<Node>, Cmp> queue;
	
	Node n;
	n.index = 0;
	n.weight = 0;
	queue.push(n);
	
	while (!queue.empty())
	{
		n = queue.top();
		queue.pop();
		
		if (visit[n.index])
		{
			continue;
		}
		visit[n.index] = true;
		
		int d = n.weight;
		dist[n.index] = (d < dist[n.index]) ? d : dist[n.index];
		
		for (int i = 0; i < count; i++)
		{
			if (map[n.index][i] != 0 && !visit[i])
			{
				Node temp;
				temp.index = i;
				temp.weight = dist[n.index] + map[n.index][i];
				
				queue.push(temp);
			}
		}
	}
	
	std::cout << dist[count - 1];
	
	return 0;
}
