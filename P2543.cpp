//resouce : https://www.luogu.org/problem/show?pid=2543
//data struct : --
//algorithm : dynamic plan
//language : C++
//IDE : Dev C++
//2016.12.15
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX(_X_, _Y_) (_X_ > _Y_) ? _X_ : _Y_

char* str1 = NULL;
char* str2 = NULL;

int** map = NULL;

int main()
{
	str1 = new char[10000];
	str2 = new char[10000];
	
	int len1 = 0;
	int len2 = 0;
	
	while (true)
	{
		char c = 0;
		c = getchar();
		
		if (c == ' ')
		{
			break;
		}
		
		str1[len1] = c;
		len1++;
	}
	
	while (true)
	{
		char c = 0;
		c = getchar();
		
		if (c == ' ' || c == '\n')
		{
			break;
		}
		
		str2[len2] = c;
		len2++;
	}
	
	map = new int*[len1 + 1];
	for (int i = 0; i <= len1; i++)
	{
		map[i] = new int[len2 + 1];
		for (int j = 0; j <= len2; j++)
		{
			map[i][j] = 0;
		}
	}
	
	for (int j = 1; j <= len2; j++)
	{
		for (int i = 1; i <= len1; i++)
		{
			if (str1[i-1] == str2[j-1])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				map[i][j] = MAX(map[i-1][j], map[i][j-1]);
			}
		}
	}
	
	std::cout << map[len1][len2] << std::endl;
	
	return 0;
}
