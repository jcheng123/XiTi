#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setZeros(vector<vector<int>>& matrix)
{
	vector<int> cols;
	vector<int> rows;
	int X = matrix.size();
	int Y = matrix[0].size();

	for(auto i = 0; i != X; ++i)
		for(auto j = 0; j != Y; ++j)
		{
			if(matrix[i][j] == 0)
			{
                cols.push_back(j);
                rows.push_back(i);
		    }
		}

	for(auto i = 0; i != cols.size(); ++i)
	{
		size_t x = rows[i], y = cols[i];
		for(auto s = 0; s != X; ++s)
			matrix[s][y] = 0;
        
		for(auto t = 0; t != Y; ++t)
			matrix[x][t] = 0;
	}
}

int main()
{
	vector<vector<int>> matrix = {{0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
	setZeros(matrix);

	for(auto i : matrix)
	{
		for(auto j : i)
			cout << j << "\t";
		cout << endl;
	}
	return 0;
}