#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> res(numRows, vector<int>(1,0));
    for(auto i = 0; i != numRows; ++i)
    {
    	res[i].resize(i + 1);
    	res[i][0] = 1;
    	res[i][i] = 1;
    }

    for(int i = 1; i <= numRows - 1; ++i)
    	for(int j = 1; j < i; j++)
    		res[i][j] = res[i - 1][j - 1] + res[i - 1][j];

    return res;
}

int main()
{
	int numRows = 5;

	vector<vector<int>> res = generate(numRows);
	for(auto i = 0; i != numRows; ++i)
	{
		for(auto j = 0; j != res[i].size(); ++j)
			cout << res[i][j] << "\t";
		cout << endl;
	}
	return 0;

}