//resouce : https://www.luogu.org/problem/show?pid=1744
//data struction : queue, adjacency list
//algorithm : SPFA
//language : C++
//IDE : Visual Studio 2013
//2016.10.29

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

struct Point
{
	int x;
	int y;
};

struct Edge
{
	int to;
	double weight;
};

typedef std::vector<Edge> LinkMap;

inline double getDistance(int, int, int, int);

int main()
{
	int shop_count = 0;
	std::cin >> shop_count;

	Point* pos = new Point[shop_count];
	for (int i = 0; i < shop_count; i++)
	{
		int x = 0;
		int y = 0;
		std::cin >> x >> y;

		pos[i].x = x;
		pos[i].y = y;
	}

	int path_count = 0;
	std::cin >> path_count;

	LinkMap* map = new LinkMap[shop_count];
	for (int i = 0; i < path_count; i++)
	{
		int f = 0;
		int t = 0;
		std::cin >> f >> t;

		f--; t--;

		Edge e;
		e.to = t;
		e.weight = getDistance(pos[f].x, pos[f].y, pos[t].x, pos[t].y);

		map[f].push_back(e);

		e.to = f;
		map[t].push_back(e);
	}

	int begin = 0;
	int target = 0;
	std::cin >> begin >> target;

	begin--; target--;

	bool* visit = new bool[shop_count];
	double* min_path = new double[shop_count];

	for (int i = 0; i < shop_count; i++)
	{
		visit[i] = false;
		min_path[i] = 9999999.9;
	}

	std::queue<int> queue;
	queue.push(begin);
	visit[begin] = true;
	min_path[begin] = 0;

	while (!queue.empty())
	{
		int index = queue.front();
		queue.pop();

		for (int i = 0; i < map[index].size(); i++)
		{
			Edge e = map[index][i];
			double weight = e.weight + min_path[index];

			if (min_path[e.to] > weight)
			{
				min_path[e.to] = weight;
				if (!visit[e.to])
				{
					visit[e.to] = true;
					queue.push(e.to);
				}
			}
		}

		visit[index] = false;
	}

	printf("%.2lf", min_path[target]);

	//system("pause");
	return 0;
}

inline double getDistance(int x1, int y1, int x2, int y2)
{
	int sub_x = abs(x1 - x2);
	int sub_y = abs(y1 - y2);

	return sqrt(sub_x* sub_x + sub_y * sub_y);
}