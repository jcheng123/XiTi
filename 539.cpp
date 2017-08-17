#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> t1, pair<int, int> t2)
{
	if(t1.first > t2.first) return true;
	else if(t1.first == t2.first && t1.second > t2.second)
		return true;
	return false;
}

int findMinDifference(vector<string>& timePoints)
{
	int time = 0;
	vector<int> T;
	string str = "";

	for(auto i = 0; i != timePoints.size(); ++i)
	{
       for(auto j = 0; j != timePoints[i].size(); ++j)
       {	
       	  if(timePoints[i][j] != ':') str += timePoints[i][j];
       	  else  { time += 60 * atoi(str.c_str()); str = ""; }
       }
       time += atoi(str.c_str());
       str = "";
       T.push_back(time);
       time = 0;
	}

	sort(T.begin(), T.end());
	T.push_back(T[0]);
	int min_inter = 1440;

	for(auto i = 0; i != T.size() - 1; ++i)
	{
		int max_min = max(T[i], T[i + 1]) - min(T[i], T[i + 1]);
		min_inter = min(min_inter, min(1440 - max_min, max_min));
	}


    return min_inter;

}

int main()
{
	vector<string> num = {"23:59", "00:00", "00:12"};
	cout << findMinDifference(num) << endl;
	return 0;
}