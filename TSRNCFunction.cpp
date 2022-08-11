#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
#include <limits>
#include <unistd.h>
#include <windows.h>

using namespace std;

const int np = 10;
vector<double> Random_num(); // declare function first

int main()
{
    vector<double> v;
    int count;
    v = Random_num();
    cout.precision(5);
    for (count = 0; count < np; count++)
    {
        cout << fixed << v[count] << '\n';
    }
}

vector<double> Random_num() // the function is get random number and pack it
{
    int i;
    double r;
    vector<double> vec;
    srand((unsigned)time(NULL));
    for (i = 0; i < np; i++)
    {
        r = (double)rand() / (RAND_MAX + 1.0);
        vec.push_back(r);
    }
    return vec;
}
