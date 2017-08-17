#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) 
{
	if(tringle.empty()) return 0;
	int m = triangle.size(), n = 0;
	for(auto& i : triangle)
		n = max(n, (int)i.size());

	vector<vector<int>> a(m, vector<int>(n, 0));

	for(auto j = 0; j < triangle[m - 1].size(); ++j)
		a[m - 1][j] = triangle[m - 1][j];

	for(int i = m - 2; i >= 0; --i)
		for(int j = triangle[i + 1].size() - 2; j >= 0; --j)
	     	a[i][j] = min(a[i + 1][j], a[i + 1][j + 1]) + triangle[i][j];
    return a[0][0];
}

int main()
{
	vector<vector<int>> res = { {2}, {3,4}, { 6,5,7 }, {4,1,8,3}};
	cout << minimumTotal(res) << endl;
	return 0;
}
