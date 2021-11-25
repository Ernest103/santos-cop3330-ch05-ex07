/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Ernesto Santos
 */


#include <iostream>
#include <math.h>
using namespace std;

double* quadraticFormula(double a, double b, double c);
double roots(double a, double b, double c);

const double INVALID = -999999;

int main()
{
	double a, b, c;
	double* results;
	cout << "Enter the variables a, b, c for your quadratic equation: ";
	cin >> a >> b >> c;

	results = quadraticFormula(a, b, c);
	if (results != NULL)
	{
		cout << "The results found where: \n"
			<< "x = " << results[0] << "\n"
			<< "x = " << results[1] << "\n";
	}
}

double* quadraticFormula(double a, double b, double c)
{
	double result[2];
	double result_pos, result_neg;
	bool flag = true;

	result_pos = roots(a, b, c);
	result_neg = -1 * result_pos;

	if (result_pos == INVALID)
	{
		cout << "The given values result in imaginary roots\n";
		return NULL;
	}
	else
	{
		//calculation for positive root result
		result[0] = ((-1.0 * b) + result_pos) / (2.0 * a);
		//calculation for negative root result
		result[1] = ((-1.0 * b) + result_neg) / (2.0 * a);
	}

	return result;
}

double roots(double a, double b, double c)
{
	double value = pow(b, 2) - (4.0 * a * c);

	if (value < 0)
		return INVALID;

	return sqrt(value);
}


/*Ex 7:
* Quadratic equations are of the form a · ax^2 + bx + c
= 0
To solve these, one uses the quadratic formula:
There is a problem, though: if b2–4ac is less than zero,
then it will fail. Write a program that can calculate x for
a quadratic equation. Create a function that prdoubles out
the roots of a quadratic equation, given a, b, c. When
the program detects an equation with no real roots,
have it prdouble out a message. How do you know that
your results are plausible? Can you check that they are
correct?
*/