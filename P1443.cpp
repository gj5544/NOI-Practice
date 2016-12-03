//resouce : https://www.luogu.org/problem/show?pid=1443
//data struct : queue
//algorithm : BFS
//language : C++
//IDE : Dev C++
//2016.11.22

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

struct Node
{
	int x;
	int y;
	int len;
};

int width = 0;
int height = 0;

int** map = NULL;

void find(int, int);

int main()
{
	std::cin >> width >> height;
	
	map = new int*[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new int[height];
		for (int j = 0; j < height; j++)
		{
			map[i][j] = -1;
		}
	}
	
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	x--;y--;
	
	find(x, y);
	
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%-5d", map[i][j]);
		}
		std::cout << std::endl;
	}
	
	return 0;
}

void find(int x, int y)
{
	Node n;
	n.len = 0;
	n.x = x;
	n.y = y;
	
	std::queue<Node> queue;
	queue.push(n);
	
	while (!queue.empty())
	{
		n = queue.front();
		queue.pop();
		
		if (map[n.x][n.y] != -1)
		{
			continue;
		}
		
		map[n.x][n.y] = n.len;
		
		int nx = n.x + 1;
		int ny = n.y - 2;
		
		if (nx < width && ny > -1)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x + 2;
		ny = n.y - 1;
		
		if (nx < width && ny > -1)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x + 2;
		ny = n.y + 1;
		
		if (nx < width && ny < height)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x + 1;
		ny = n.y + 2;
		
		if (nx < width && ny < height)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x - 1;
		ny = n.y + 2;
		
		if (nx > -1 && ny < height)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x - 2;
		ny = n.y + 1;
		
		if (nx > -1 && ny < height)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x - 1;
		ny = n.y - 2;
		
		if (nx > -1 && ny > -1)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
		
		nx = n.x - 2;
		ny = n.y - 1;
		
		if (nx > -1 && ny > -1)
		{
			Node temp;
			temp.len = n.len + 1;
			temp.x = nx;
			temp.y = ny;
			
			queue.push(temp);
		}
	}
}
