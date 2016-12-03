//resource : https://www.luogu.org/problem/show?pid=1208
//data struction : --
//algorithm : greedy
//language : C++
//IDE : Visual Studio 2013
//2016.12.3
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MIN(_X_, _Y_) (_X_ > _Y_) ? _Y_ : _X_

struct Milk
{
	int price;
	int val;
};

int need = 0;
int count = 0;

Milk* list = NULL;

int cmp(const void*, const void*);

int main()
{
	std::cin >> need >> count;

	list = new Milk[count];
	for (int i = 0; i < count; i++)
	{
		int p = 0;
		int v = 0;
		std::cin >> p >> v;

		list[i].price = p;
		list[i].val = v;
	}

	qsort(list, count, sizeof(Milk), cmp);

	int p = 0;
	int cost = 0;

	while (need > 0)
	{
		if (list[p].val <= need)
		{
			cost += list[p].price * list[p].val;
			need -= list[p].val;
		}
		else
		{
			cost += list[p].price * need;
			need -= list[p].val;
		}

		p++;
	}

	std::cout << cost;

	return 0;
}

int cmp(const void* a, const void* b)
{
	Milk* ma = (Milk*)a;
	Milk* mb = (Milk*)b;

	return ma->price - mb->price;
}