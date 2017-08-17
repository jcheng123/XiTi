#include <iostream>
#include <vector>

using namespace std;

vector<int> SO(vector<vector<int>>& matrix, int sx, int sy, int ex, int ey)
{
	vector<int> r;
	if(sx >= 0 && ex >= 0 && sx <= ex && sy >= 0 && ey >= 0 && sy <= ey)
	{
	    int X = ex - sx + 1, Y = ey - sy + 1;

		for(auto j = sy; j < ey + 1; ++j)
			r.push_back(matrix[sx][j]);

		for(auto i = sx + 1; i < ex + 1; ++i)
			r.push_back(matrix[i][ey]);

	    if(X != 1)
		{
			for(auto j = ey - 1; j >= sy; --j)
	           r.push_back(matrix[ex][j]);
	    }

	    if(Y != 1)
	    {
	    	for(auto i = ex - 1; i > sx; --i)
	    		r.push_back(matrix[i][sy]);


	    }

	    vector<int> res = SO(matrix, sx + 1, sy + 1, ex - 1, ey - 1);
	

	    r.insert(r.end(), res.begin(), res.end());
	}
    return r;
}

// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]

int main()
{
	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> r = SO(matrix, 0, 0, 2, 2);

	for(auto i : r)
		cout << i << "\t";
	cout << endl;

	return 0;
}