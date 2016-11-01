//resouce : https://www.luogu.org/problem/show?pid=2616
//data struction : --
//algorithm : Greedy
//language : C++
//IDE : Dev C++ 5.11
//2016.11.1
#include <iostream>
#include <cstdio>
#include <cstdlib>

struct Object
{
	int count;
	int price;
};

int cmp(const void* a, const void* b)
{
	Object* oa = (Object*)a;
	Object* ob = (Object*)b;
	
	return oa->price - ob->price;
}

int main()
{
	int need = 0;
	int length = 0;
	int count = 0;
	std::cin >> need >> length >> count;
	
	Object* obj = new Object[count];
	for (int i = 0; i < count; i++)
	{
		int pos = 0;
		int c = 0;
		int p = 0;
		std::cin >> pos >> c >> p;
		
		obj[i].count = c;
		obj[i].price = p + length - pos;
	}
	
	qsort(obj, count, sizeof(Object), cmp);
	
	int cost = 0;
	int index = 0;
	
	for (int i = 0; i < count; i++)
	{
		for (int k = 0; k < obj[i].count; k++)
		{
			cost += obj[i].price;
			need--;
			
			if (need == 0)
			{
				std::cout << cost;
				return 0;
			}
		}
	}
	
	std::cout << cost;
	
	return 0;
}
