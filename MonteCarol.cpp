// Edit By XuRL 20210703 15:00
// Monte-Carlo algorithm
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
#include <limits>
#include <unistd.h>
#include <windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

// create class "Particle"
class Particle
{
public:
	double x_old;
	double x_new;
	double y_old;
	double y_new;
	double U_old;
	double U_new;
};

// declare variable
const int NP = 50;
const double boundary = 5;
const double step = 0.1;
const int t_end = 150;
const double kB_T = 1.0; // in computer, multiplication is faster than division
const string dir = "D:/google drive/cpp/MonteCarloData/";

// declare function
void ini_p(vector<Particle> &arr);
double Random_num();
void print_array(const vector<Particle> &arr);
void update_data(vector<Particle> &arr);
void get_total_potential(vector<Particle> &arr);
double potential_42(double dx, double dy);
void Monte_Carlo(vector<Particle> &arr);
void write_in_txt(string filename, const int time, const vector<Particle> &arr);

// main programme
int main()
{
	srand(time(NULL)); // Global variable
	vector<Particle> p_arr;
	ini_p(p_arr);
	print_array(p_arr);

	for (int t = 0; t < t_end; t++)
	{
		update_data(p_arr);
		get_total_potential(p_arr);
		Monte_Carlo(p_arr);
		write_in_txt(dir, t, p_arr);
		cout << "time= " << t << endl;
	}
	p_arr.clear();
	p_arr.shrink_to_fit();
	return 0;
}

// function of giving initial position
void ini_p(vector<Particle> &arr)
{
	Particle temp;
	for (int n = 0; n < NP; n++)
	{
		temp.x_old = 0.0;
		temp.x_new = Random_num() * boundary;
		temp.y_old = 0.0;
		temp.y_new = Random_num() * boundary;
		temp.U_old = 0.0;
		temp.U_new = 0.0;

		arr.push_back(temp);
	}
}

// function of getting random number of time series
double Random_num()
{
	double R;
	R = rand() / (RAND_MAX + 1.0);
	return R;
}

// function of print array
void print_array(const vector<Particle> &arr)
{
	for (auto k = 0; k < arr.size(); k++)
	{
		cout << arr[k].x_new << " " << arr[k].y_new << " " << arr[k].U_old << endl;
	}
}

// function of update data
void update_data(vector<Particle> &arr)
{
	for (auto l = 0; l < arr.size(); l++)
	{
		arr[l].x_old = arr[l].x_new;
		arr[l].y_old = arr[l].y_new;
		arr[l].x_new = arr[l].x_new + (step * (Random_num() - 0.5));
		if (arr[l].x_new > boundary || arr[l].x_new < 0.0)
		{
			arr[l].x_new = arr[l].x_old;
		}
		arr[l].y_new = arr[l].y_new + (step * (Random_num() - 0.5));
		if (arr[l].y_new > boundary || arr[l].y_new < 0.0)
		{
			arr[l].y_new = arr[l].y_old;
		}
		arr[l].U_old = arr[l].U_new;
	}
}

// function of getting potential between "the one partcile" and "the other particles"
void get_total_potential(vector<Particle> &arr)
{
	double dx, dy;
	for (auto i = 0; i < arr.size(); i++)
	{
		double U = 0.0; // zero
		for (auto j = 0; j < arr.size(); j++)
		{
			if (i != j)
			{
				dx = arr[i].x_new - arr[j].x_new;
				dy = arr[i].y_new - arr[j].y_new;

				U += potential_42(dx, dy);
			}
		}
		arr[i].U_new = U;
	}
}

// function of getting potential between "the one particle" and "the other particle"
double potential_42(double dx, double dy)
{
	double dr_2 = dx * dx + dy * dy;
	double U = (1 / (dr_2 * dr_2)) - (1 / (dr_2));
	return U;
}

// function of comparing each particle of old step and new step
void Monte_Carlo(vector<Particle> &arr)
{
	double dU;
	for (auto i = 0; i < arr.size(); i++)
	{
		dU = arr[i].U_new - arr[i].U_old;
		if (dU >= 0)
		{
			if (Random_num() > exp(-dU * kB_T))
			{
				arr[i].x_new = arr[i].x_old;
				arr[i].y_new = arr[i].y_old;
			}
		}
	}
}

// function of writting in text file
void write_in_txt(string filename, const int time, const vector<Particle> &arr)
{
	ofstream myfile;
	filename = filename + to_string(time) + ".txt";
	myfile.open(filename);

	myfile << "x y U" << endl;
	for (auto k = 0; k < arr.size(); k++)
	{
		myfile << arr[k].x_new << " " << arr[k].y_new << " " << arr[k].U_old << endl;
	}
	myfile.close();
}