//运算符重载
#include<iostream>
#include<stdlib.h>
#include<string>
class Rational
{
public:
	Rational operator+(Rational rhs);
	Rational operator-(Rational rhs);
	Rational operator*(Rational rhs);
	Rational operator/(Rational rhs);

	Rational(int zi, int mu);
private:
	void normalize();

	int numerator;
	int denominator;

	friend std::ostream& operator<<(std::ostream& os, Rational A);
};


void Rational::normalize()
{
	if (denominator < 0)//保证分母为正
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	int a, b;
	a = abs(numerator);
	b = abs(denominator);
	//求最大公约数
	while (b > 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}

	numerator /= a;
	denominator /= b;
}
Rational::Rational(int zi,int mu) 
{
	numerator = zi;
	denominator = mu;
	normalize();
}
Rational Rational::operator+(Rational rhs)
{
	int a,b,c,d;
	a = numerator;
	b = denominator;
	c = rhs.numerator;
	d = rhs.denominator;
	
	int fenzi = a * d + b * c;
	int fenmu = b * d;
	return Rational(fenzi, fenmu);
}
Rational Rational::operator-(Rational rhs)
{
	rhs.numerator = -rhs.numerator;
	return operator+(rhs);
}
Rational Rational::operator*(Rational rhs)
{
	int a = numerator * rhs.numerator;
	int b = denominator * rhs.denominator;
	return Rational(a, b);
}
Rational Rational::operator/(Rational rhs)
{
	int temp = rhs.numerator;
	rhs.numerator = rhs.denominator;
	rhs.denominator = temp;

	return operator*(rhs);
}

std::ostream& operator<<(std::ostream& os, Rational A);

int main()
{
	Rational f1(3,5);
	Rational f2(4,8);

	std::cout << f1 << "+" << f2 << "==" << (f1 + f2) << std::endl;
	return 0;
}

std::ostream& operator<<(std::ostream& os, Rational A)
{
	os << A.numerator << "/" << A.denominator;
	return os;
}