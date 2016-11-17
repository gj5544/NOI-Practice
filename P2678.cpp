//resouce : https://www.luogu.org/problem/show?pid=1351
//data struct : --
//algorithm : greedy, binary search
//language : C++
//IDE : Dev C++
//2016.11.17

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

typedef long long lint;

int main()
{
	std::ios::sync_with_stdio(false);
 	
 	int length = 0;
 	int count = 0;
 	int need = 0;
 	std::cin >> length >> count >> need;
 	
 	lint* stones = new lint[count + 1];
 	for (int i = 0; i < count; i++)
 	{
 		lint len = 0;
 		std::cin >> len;
 		
 		stones[i] = len;
	}
	
	stones[count] = length;
	
	lint del = 0;
	lint min = length / 2;
	int last = 0;
	int left = 0;
	int right = length;
	int ans = 0;
	
	while (left <= right)
	{	
		del = 0;
		last = 0;
		min = (left + right) / 2;
		
		for (int i = 0; i < count + 1; i++)
		{
			int sub = stones[i] - last;
			if (sub < min)
			{
				del++;
				
				if (del > need)
				{
					break;
				}
			}
			else
			{
				last = stones[i];
			}
		}
		
		if (del <= need)
		{
			ans = left;
			left = min + 1;
			
			continue;
		}
		else
		{
			right = min - 1;
		}
	}
	
	if (left > right)
	{
		ans = left - 1;
	}
	
	std::cout << ans;
	
	return 0;
}
