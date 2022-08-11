#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    vector<double> vec;
    int i;
    unsigned seed; // define random number seed

    seed = (unsigned)time(NULL); // connect the relation between random number and seed
    srand(seed);
    cout.precision(8);

    for (i = 0; i < 5; i++)
    {
        double r = (double)rand() / (RAND_MAX + 1.0);
        vec.push_back(r);
        cout << "random number = " << fixed << vec[i] << "\n";
    }
    cout << "vec size = " << vec.size() << endl;
}