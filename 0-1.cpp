//построить таблицу приближенных значений функции -sin2x+2xcos2x на отрезке [-2pi; 2pi] с шагом pi/4.
#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846
using namespace std;

double F(double x)
{
	double fx = -sin(x + x) + 2 * x * cos(x + x);
	return fx;
}

double f(double x, double eps) {
	double sin2x = x, cos2x=x, s1 = 0, s2=0;
	//sin
	for (int i = 1; fabs(sin2x) > eps; ++i) {
		s1 += sin2x;
		sin2x *= (-4) * x * x / ((2 * i) * (2 * i + 1));
	}

	//cos
	for (int i = 1; fabs(cos2x) > eps; ++i)	
	{	s2 += cos2x;
		cos2x *= (-4) * x * x / ((2 * i - 1) * (2 * i));
	}
	double fx = -s1 + 2 * x * s2;
	return fx;
}

 void printTable(double a, double b, double h, double eps) {
	cout << "\nFunction value table\n\n";
	for (double x = a; x <= b + h / 2; x += h) {
		cout << "x=" << x << " " << "f(x)=" << f(x, eps) << " " << "F(x)=" << F(x) << "\n";
	}
}

int main() {
	double a=-PI-PI, b=PI+PI, h=PI/4, eps=0.0001;
	printTable(a, b, h, eps);
	return 0;
}