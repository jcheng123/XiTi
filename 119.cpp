#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;

	for(auto i = 1; i <= rowIndex; i++)
	{
		res[i] = double(rowIndex - i + 1) / double(i) * res[i - 1] + 0.2;
	}

	return res;
}

int main()
{
	int row = 11;
	vector<int> res = getRow(row);
	for(auto i : res)
		cout << i << "\t";
	cout << endl;
	return 0;
}