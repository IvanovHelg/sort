
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include <cstdlib>

using namespace std::chrono;
using std::cout;
using std::cin;
using std::string;
using namespace std;

int rand_uns(int min, int max)
{
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    static default_random_engine e(seed);
    uniform_int_distribution<int> d(min, max);
    return d(e);
}

void output(string name, string file)
{
    std::ofstream resout(file, std::ios::app);
    if (resout.is_open()) {
        resout << name << std::endl;
    }
    resout.close();
}

int partition(int *a, int start, int end)
{
    int pivot=a[end];
    int P_index=start;
    int i, t;
    for(i = start; i < end; i++)
    {
        if(a[i] <= pivot)
        {
            t =a [i];
            a[i] = a[P_index];
            a[P_index] = t;
            P_index++;
        }
    }
    t = a[end];
    a[end] = a[P_index];
    a[P_index] = t;
    return P_index;
}
void QuickSort(int *a, int start, int end)
{
    if(start < end)
    {
        int P_index = partition(a,start,end);
        QuickSort(a, start,P_index-1);
        QuickSort(a,P_index+1, end);
    }
}
int main()
{
    for (int j = 1000; j < 100000; j = j + 500)
    {
        int* arr = (int*)malloc(sizeof(int)*j);
        for (int i = 0; i < j; ++i)
        {
            arr[i] = rand_uns(0, 100000);
        }
        auto start = std::chrono::high_resolution_clock::now();
        QuickSort(arr, 0, j-1);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "quick.txt");
        free(arr);
    }
    return 0;
}




