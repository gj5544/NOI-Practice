//resource : https://www.luogu.org/problem/show?pid=1201
//data struction : std::map
//algorithm : simulation
//language : C++
//IDE : Dev C++
//2016.11.3
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

int main()
{
	std::map<std::string, int> list;
	
	int count = 0;
	std::cin >> count;
	
	std::string* names = new std::string[count];
	for (int i = 0; i < count; i++)
	{
		std::string name = "";
		std::cin >> name;
		
		list[name] = 0;
		names[i] = name;
	}
	
	for (int i = 0; i < count; i++)
	{
		std::string myself = "";
		int total = 0;
		int target = 0;
		std::cin >> myself >> total >> target;
		
		if (target == 0)
		{
			continue;
		}
		
		int one = total / target;
		
		for (int j = 0; j < target; j++)
		{
			std::string name = "";
			std::cin >> name;
			list[name] += one;
		}
		
		list[myself] -= total;
		list[myself] += total % target;
	}
	
	for (int i = 0; i < count; i++)
	{
		std::cout << names[i] << " " << list[names[i]] <<std::endl;
	}
	
	return 0;
}
