//resouce : https://www.luogu.org/problem/show?pid=3370
//data struct : set
//algorithm : hash
//language : C++
//IDE : Dev C++
//2016.12.15
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>

#define HASH1 233
#define HASH2 666
#define HASH3 909
#define HASH4 519

std::set<int> set;

int hash(std::string);

int main()
{
	int count = 0;
	std::cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		std::string str = "";
		std::cin >> str;
		
		int h = hash(str);
		set.insert(h);
	}
	
	std::cout << set.size() << std::endl;
	
	return 0;
}

int hash(std::string s)
{
	int len = s.length();
	int h = 0;
	
	for (int i = 0; i < len; i++)
	{
		h += HASH1 * s[i*HASH4%len] * s[i*HASH2%len] * s[i*HASH3%len];
	}
	
	return h;
}
