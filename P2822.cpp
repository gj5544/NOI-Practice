//resouce : https://www.luogu.org/problem/show?pid=2822
//data struct : --
//algorithm : --
//language : C++
//IDE : Dev C++
//2016.12.2
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define min(_X_,_Y_)(_X_<_Y_) ? _X_:_Y_

struct Point
{
    int n;
    int m;
    int index;
};

int map[2001][2001];
int ans[2001][2001];

int main()
{
    int count = 0;
    int k = 0;
    std::cin >> count >> k;
    
    map[0][0] = 1;
    map[1][0] = 1;
    map[1][1] = 1;
    
    for (int i = 2; i < 2001; i++)
    {
        for (int j = 0; j <= i; j++)
        {
        	if (j == 0)
        	{
        		map[i][j] = 1;
			}
			else
			{
				map[i][j] = map[i-1][j] % k + map[i-1][j-1] % k;
           		map[i][j] %= k;
			}
        }
    }
    
    ans[0][0] = 0;
    ans[1][0] = 0;
    ans[1][1] = 0;
   	
	for (int i = 1; i <= 2000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
        	if (j == 0)
        	{
        		ans[i][j] = ans[i-1][j];
			}
			else if (i == j)
			{
				ans[i][j] = ans[i][j - 1];
			}
			else
			{
				ans[i][j] = ans[i][j-1] + ans[i-1][j] - ans[i - 1][j - 1];
			}
        	
        	if (map[i][j] % k == 0)
            {
            	ans[i][j]++;
			}
        }
    }
    
    for (int i = 0; i < count; i++)
    {
    	int x = 0;
    	int y = 0;
        std::cin >> x >> y;
		std::cout << ans[x][min(x, y)] << std::endl; 
    }
    
    return 0;
}
