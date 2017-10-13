// MCS 360 Project Two by David Awosusi and Houssem Boundaoui

#include "series.h"
#include <iostream>
#include <random>
#include <cstdlib>

int main()
{
	cout << "Testing the arithmetic on truncated power series..." << endl;

	std::random_device rd; // obtain a seed for the random number engine
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-1, +1);

	// to store the degree
	int degree;
	// read the degree
	cout << "Give the degree : ";
	cin >> degree;

	// showing the
	cout << "A random series of degree " << degree << " , called A" << endl;

	// set the coefficient values
	vector<double> c;

	// add dummy values
	for (int i = 0; i<degree + 1; i++)
		c.push_back(0);

	// assign values
	for (int i = 0; i < degree + 1; i++)
		c[i] = dis(gen);

	Series A(degree, c);
	cout << "series A : " << A.to_string() << endl;

	cout << "and another random series of degree " << degree << " , called B" << endl;

	// assign values
	for (int i = 0; i < degree + 1; i++)
		c[i] = dis(gen);
	Series B(degree, c);

	cout << "series B : " << B.to_string() << endl;

	Series one = A + B;
	Series two = A + B - B;
	Series multiply = A * B;
	Series divide = A * B/B;

	cout << "A + B : " << one.to_string() << endl;
	cout << "A + B - B : " << two.to_string() << endl;
	cout << "A * B : " << multiply.to_string() << endl;
	cout << "A * B/B : " << divide.to_string() << endl;

	Series x = A;
	Series x_0 = A;
	cout << "Testing newton method on the square root of a random series : " << endl;
	
	Series del_x;
	Series fx;

	Series _2(0, 2);
	Series last_x = A;
	
	Series x_i = last_x + A;
	

	for (int k = 0; k < 5; k++)
	{
		cout << "at step " << k << " : " << endl;
		Series t = x*x;
		fx = x_0 - t;
		//Series del_x = fx / (_2 * x);
		//Series x_i = last_x + del_x;
		//last_x = x_i;
		// x = x_i;

		cout << "fx : " << fx.to_string() << endl;
		cout << "dx : " << del_x.to_string() << endl;
		cout << "x : " << x_i.to_string() << endl;
	}


	int k;
	cin >> k;
}