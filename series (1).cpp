
// MCS 360 Project Two by David Awosusi and Houssem Boundaoui

#include "series.h"

// completing the default constructor
Series::Series()
{
	degree = 0;	 // set the degree to 0
	// set the coefficients to zero
	for (int i = 0; i<degree + 1; i++)
		coefficients.push_back(0);
}
// first constructor that takes only the degree as the
// parameter and returns a series with zero coefficients.
Series::Series(int degree)
{
	// set the degree to the argument passed
	this->degree = degree;
	// set the coefficients to zero
	for (int i = 0; i<degree + 1; i++)
		coefficients.push_back(0);
}

// second constructor that takes the degree and the constant
// of the series as the parameter.
Series::Series(int degree, int c)
{
	// set the degree to the argument passed
	this->degree = degree;

	// set the coefficients to zero
	for (int i = 0; i<degree + 1; i++)
		coefficients.push_back(0);
	// setting the coefficient for zero degree
	coefficients[0] = c;
}

// third constructor allows to specify all coefficients of the series
Series::Series(int degree, vector<double> values)
{
	this->degree = degree;
	for (int i = 0; i<degree + 1; i++)
		coefficients.push_back(0);

	// copy coefficients
	for (int i = 0; i<degree + 1; i++)
		coefficients[i] = values[i];
}

//  Copy method: copies the degree and the coefficients
//  to the object the copy method is applied to.
Series Series::copy()
{
	// create a new series object using the values of the current object
	Series newSeries(degree, coefficients);
	return newSeries;
}

// to string method
string Series::to_string()
{
	string s = "";

	for (int i = 0; i<degree + 1; i++)
	{
		if (i == 0)
		{
			s = s + std::to_string(coefficients[i]) + " ";
		}
		else
		{
			if (coefficients[i] > 0)
			{
				s = s + "+" + std::to_string(coefficients[i]) + "t^" + std::to_string(i) + " ";
			}
			else if (coefficients[i] < 0)
			{
				s = s + std::to_string(coefficients[i]) + "t^" + std::to_string(i) + " ";
			}
			else
			{
				// add nothing for 0 coefficient
			}
		}
	}
	return s;
}

// overload operators
Series& Series::operator=(const Series & other)
{
	if (this != &other)
	{
		this->degree = other.degree;
		this->coefficients = other.coefficients;
	}
	return *this;
}


Series Series::operator+(const Series & rhs)
{
	// the final degree of the addition is the larger of two
	if (this->degree > rhs.degree)
	{
		// compute the final vector
		vector<double> c;

		int i;

		// add the coefficients
		for (i = 0; i<rhs.degree + 1; i++)
		{
			// add corresponding coefficients
			c.push_back(rhs.coefficients[i] + this->coefficients[i]);
		}

		// add the remaining coefficients
		while (i < this->degree + 1)
			c.push_back(this->coefficients[i]);

		// create new series
		Series newSeries(this->degree, c);
		//newSeries.degree = this->degree;
		//newSeries.coefficients = c;

		return newSeries;
	}
	else
	{
		// compute the final vector
		vector<double> c;
		int i;
		// add the coefficients
		for (i = 0; i<(this->degree + 1); i++)
		{
			c.push_back(rhs.coefficients[i] + this->coefficients[i]);
		}

		while (i < rhs.degree + 1)
			c.push_back(rhs.coefficients[i]);

		// create new series
		Series newSeries(rhs.degree, c);
		//newSeries.degree = rhs.degree;
		//newSeries.coefficients = c;

		return newSeries;
	}
}

Series Series::operator-(const Series & rhs)
{
	// the final degree of the addition is the larger of two
	if (this->degree > rhs.degree)
	{
		// compute the final vector
		vector<double> c;

		int i;
		for (i = 0; i<rhs.degree + 1; i++)
		{
			// add corresponding coefficients
			c.push_back(this->coefficients[i] - rhs.coefficients[i]);
		}
		while (i < this->degree + 1)
			c.push_back(this->coefficients[i]);

		// create new series
		Series newSeries;
		newSeries.degree = this->degree;
		newSeries.coefficients = c;

		return newSeries;
	}
	else
	{
		vector<double> c;

		int i;
		for (i = 0; i<this->degree + 1; i++)
		{
			c.push_back(this->coefficients[i] - rhs.coefficients[i]);
		}

		while (i < rhs.degree + 1)
			c.push_back(-rhs.coefficients[i]);

		Series newSeries;
		newSeries.degree = rhs.degree;
		newSeries.coefficients = c;

		return newSeries;
	}
}

Series Series::operator*(const Series & rhs)
{
	int d = this->degree + rhs.degree;
	vector<double> c;

	for (int i = 0; i<d + 1; i++)
		c.push_back(0);

	for (int i = 0; i<this->degree + 1; i++)
	{
		if (coefficients[i] == 0)
			continue;

		for (int j = 0; j<rhs.degree + 1; j++)
		{
			if (rhs.coefficients[j] == 0)
				continue;

			// the coefficient for which the power is calculated
			int pow = i + j;
			c[pow] += (coefficients[i] * rhs.coefficients[j]);
		}
	}

	Series newSeries(d, c);
	return newSeries;
}

Series Series::inverse()
{
	vector<double> c;
	for (int i = 0; i<degree + 1; i++)
		c.push_back(0);

	double total = 0;
	// set the constant variable
	c[0] = 1.0 / coefficients[0];

	for (int x = 1; x<degree + 1; x++)
	{
		total = 0;
		for (int j = 1; j <= x; j++)
		{
			total += (coefficients[j] * c[j - 1]);
		}
		c[x] = total / coefficients[0];
	}

	Series newSeries(degree, c);
	return newSeries;
}

Series Series::operator/(Series & rhs)
{
	Series newSeries = (*this) * (rhs.inverse());
	return newSeries;
}