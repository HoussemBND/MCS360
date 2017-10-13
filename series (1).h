
// MCS 360 Project Two by David Awosusi and Houssem Boundaoui

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <string>

using namespace std;

/* declaring the Series class here that represents a truncated power series
   with double as coefficients.*/
class Series
{
	// private access declaration
private:
	// the integer to store the degree
	int degree;
	// the private vector that stores the coefficients
	vector<double> coefficients;

public:
    // public access declaration
	Series();
	// constructor that takes only the degree as the parameter
	Series(int);
	// constructor that takes the degree and the constant of the series as the parameter
	Series(int, int);
	Series(int, vector<double>);
	Series copy();
	// to string method
	string to_string();

	// to get the inverse of this series
	Series inverse();

	// overload operators
	Series& operator=(const Series &);
	Series operator+(const Series & rhs);
	Series operator-(const Series & rhs);
	Series operator*(const Series & rhs);
	Series operator/( Series & rhs);
};

#endif
