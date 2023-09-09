#include<iostream>
#include<cmath>
using namespace std;

class Point {
	friend double getLine(Point& p1, Point& P2);

private:
	int x, y;
public:
	Point(int a=0, int b=0) :x(a), y(b) {};
	int getX()const { return x; };
	int getY()const { return y; };

};

double getLine(Point& p1, Point& p2)
{
	int res_X = p1.x - p2.x;
	int res_Y = p1.y - p2.y;

	return static_cast<double> (sqrt(res_X * res_X + res_Y + res_Y)) ;
}

int main()
{
	Point p1(2, 3);
	Point p2(4, 4);
	Point p3;
	double line_long;
	line_long = getLine(p1, p2);
	cout << "p1与p2连线长为" << line_long;

}