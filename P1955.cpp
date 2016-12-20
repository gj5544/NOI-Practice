//resouce : https://www.luogu.org/problem/show?pid=1955
//data struct : --
//algorithm : Union Find 
//language : C++
//IDE : Dev C++
//2016.12.16
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

#define MAX 3000010

typedef long long lint;

struct Cmd
{
	lint num1;
	lint num2;
	int cond;
};

int parent[MAX];
std::map<lint, int> index;

bool getResult(int);

int find(int);
int find_c(int);
void unionByRandom(int, int);
void init();

int main()
{
	std::ios::sync_with_stdio(false);
	
	int count = 0;
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		init();
		
		int t = 0;
		std::cin >> t;
		
		bool flag = getResult(t);
		if (flag)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
		
		index.clear();
	}
	
	return 0;
}

bool getResult(int count)
{
	std::vector<Cmd> t_list;
	std::vector<Cmd> f_list;
	
	bool flag = true;
	int k = 0;
	
	for (int i = 0; i < count; i++)
	{
		lint num1 = 0;
		lint num2 = 0;
		int cond = 0;
		
		std::cin >> num1 >> num2 >> cond;
		
		Cmd cmd;
		cmd.cond = cond;
		cmd.num1 = num1;
		cmd.num2 = num2;
		
		if (index.find(num1) == index.end())
		{
			index[num1] = k;
			k++;
		}
		if (index.find(num2) == index.end())
		{
			index[num2] = k;
			k++;
		}
		
		if (cond == 1)
		{
			t_list.push_back(cmd);
		}
		else
		{
			f_list.push_back(cmd);
		}
	}
	
	int t_size = t_list.size();
	for (int i = 0; i < t_size; i++)
	{
		Cmd cmd = t_list[i];
		unionByRandom(index[cmd.num1], index[cmd.num2]);
	}
	
	int f_size = f_list.size();
	for (int i = 0; i < f_size; i++)
	{
		Cmd cmd = f_list[i];
		
		if (find_c(index[cmd.num1]) == find_c(index[cmd.num2]))
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

int find(int x)
{
	int px = parent[x];
	while (px != parent[px])
	{
		px = parent[px];
	}
	
	int i = x;
	int j = 0;
	while (i != px)
	{
		j = parent[i];
		parent[i] = px;
		i = j;
	}
	
	return px;
}

int find_c(int x)
{
	int px = parent[x];
	while (px != parent[px])
	{
		px = parent[px];
	}
	
	return px;
}

void unionByRandom(int x, int y)
{
	int px = find(x);
	int py = find(y);
	
	if (px == py)
	{
		return;
	}
	
	parent[px] = py;
}

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
	}
}
