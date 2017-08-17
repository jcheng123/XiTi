#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double dis(vector<double> p1, vector<double> p2)
{
	return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
}


bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
{
	vector<int> center(2, 0);
	center[0] = 0.25 * double(p1[0] + p2[0] + p3[0] + p4[0]);
	center[1] = 0.25 * double(p1[1] + p2[1] + p3[1] + p4[1]);
    
    double d1 = dis(p1, center);
    double d2 = dis(p2, center);
    double d3 = dis(p3, center);
    double d4 = dis(p4, center);

    if(d1 != d2 || d1 != d3 || d1 != d4) return false;

    vector<int> cor = {2 * center[0] - p1[0], 2 * center[1] - p1[1]};
    if(cor == p2) 
    {
    	if (sqrt(2) * d2 == dis(p2, p3)) return true;
    	else return false;
    }

    if(cor == p3) 
    {
    	if (sqrt(2) * d3 == dis(p2, p3)) return true;
    	else return false;
    }

    if(cor == p4) 
    {
    	if (sqrt(2) * d4 == dis(p2, p4)) return true;
    	else return false;
    }

    return false;
}


