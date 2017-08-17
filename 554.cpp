#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int leastBricks(vector<vector<int>>& wall)
{
	map<int, vector<int>> map_n;
	int rows = wall.size();
	int sum = 0;
	int len = accumulate(wall[0].begin(), wall[0].end(), 0);
	map<int, int> map_m;
	int number_brick = 0;

	for(auto i = 0; i != rows; ++i)
	{
		for(auto j = 0; j != wall[i].size() - 1; ++j)
		{
		   sum += wall[i][j];
		   map_n[i].push_back(sum);
		}
		sum = 0;
	}

    for(auto j = map_n.begin(); j != map_n.end(); ++j)
    {
    	vector<int> res = j -> second;
    	for(auto p : res)
    	{
    		map_m[p]++;
            number_brick = max(map_m[p], number_brick);
        }
    }

    return (rows - number_brick);
}

int main()
{
    vector<vector<int>> wall = {{1,2,2,1}, {3,1,2}, {1,3,2}, {2,4}, {3,1,2}, {1,3,1,1}};
	int num = leastBricks(wall);
	cout << "num : " << num << endl;

	return 0;
}