//resouce : https://www.luogu.org/problem/show?pid=1351
//data struct : --
//algorithm : quick sort
//language : C++
//IDE : Dev C++
//2016.11.10
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

struct Edge
{
    int from;
    int to;
};

int cmp(const void* a, const void* b)
{
    Edge* ea = (Edge*)a;
    Edge* eb = (Edge*)b;

    return ea->from - eb->from;
}

int main()
{
	//std::ofstream out("link.out");
 	//std::ifstream in("link.in");
 
 	//std::cin.rdbuf(in.rdbuf());
 	//std::cout.rdbuf(out.rdbuf());
	
	std::ios::sync_with_stdio(false);
	
    int count = 0;
    std::cin >> count;

    Edge* list = new Edge[(count - 1) * 2];

    for (int i = 0; i < count - 1; i++)
    {
        int f = 0;
        int t = 0;
        std::cin >> f >> t;
        f--; t--;

        list[i].from = f;
        list[i].to = t;

        list[count + i - 1].from = t;
        list[count + i - 1].to = f;
    }

    int* weight = new int[count];
    for (int i = 0; i < count; i++)
    {
        int w = 0;
        std::cin >> w;

        weight[i] = w;
    }

    qsort(list, (count - 1) * 2, sizeof(Edge), cmp);

    int last = -1;
    int max = 0;
    long long sum = 0;

    long long sub_sum = 0;
    int first_max = -1;
    int second_max = -1;

    for (int i = 0; i < (count - 1) * 2; i++)
    {
        Edge e = list[i];

        if (e.from == last)
        {
            int temp = weight[e.to];
            sum += temp * sub_sum;
            sum = sum % 10007;
            sum += temp * sub_sum;
            sum = sum % 10007;
            sub_sum += temp;

            if (temp > first_max)
            {
                second_max = first_max;
                first_max = temp;
            }
            else if (temp > second_max)
            {
                second_max = temp;
            }
        }
        else
        {
            if (first_max != -1 && second_max != -1)
            {
                int sub_max = first_max * second_max;
                max = (sub_max > max) ? sub_max : max;
            }

            first_max = weight[e.to];
            second_max = -1;

            last = e.from;
            sub_sum = weight[e.to];
        }
    }

    std::cout << max << " " << sum ;

    return 0;
}
