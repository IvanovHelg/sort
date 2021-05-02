/*
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

int main() {
    int N = 1000000;
    int* arr = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand_uns(0, 10000);
    }
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N - 1; i++) {
        int min;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[i]) {
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;

            }

        }
    }

    free(arr);

    return 0;
}