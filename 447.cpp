#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <cmath>

using namespace std;

int numberOfBoomerangs(vector<pair<int, int>>& points)
{
	map<pair<size_t, int>, int> map_n;

	for(auto i = 0; i != points.size(); ++i)
		for(auto j = 0; j != points.size(); ++j)
		{
			if(j == i) continue;
			pair<size_t, int> cord = {i, pow(points[i].first - points[j].first, 2) 
				                         + pow(points[i].second - points[j].second, 2)};
            map_n[cord]++; 
		}

    int sum = 0;
    for(auto i = map_n.begin(); i != map_n.end(); ++i)
    {
    	int m = i -> second;
    	sum += (m * (m - 1)) >> 1;
    }

    return sum;
}