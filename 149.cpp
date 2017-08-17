#include <iostream>
#include <vector>

using namespace std;

struct Point {
   int x;
   int y;
   Point() : x(0), y(0) {}
   POint(int a, int b) : x(a), y(b) {}
};

struct Line {
    double slope;
    double trunc;
    Line(double s, double t) : slope(s), trunc(t) {}
};

int maxPoints(vector<Point>& points) 
{
	if(points.empty()) return 0;
	
}
