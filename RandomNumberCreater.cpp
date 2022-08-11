#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{

    vector<double> vec; // declare vector "vec"
    int i;
    cout.precision(8); // fix "cout" that can output double type variable (after point 8 digits)

    for (i = 0; i < 5; i++)
    {
        double r = (double)rand() / (RAND_MAX + 1.0); // "r" variable is random number between 0 and 1
        vec.push_back(r);                             // insert the random number to vector "vec"
        cout << "random number = " << fixed << vec[i] << "\n";
    }
    cout << "vec size = " << vec.size() << endl;
}