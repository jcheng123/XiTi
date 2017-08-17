#include <iostream>
#include <map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
{
	map<int, int> map_AB;
	map<int, int> map_CD;

	for(auto i = 0; i != A.size(); ++i)
		for(auto j = 0; j != B.size(); ++j)
			map_AB[A[i] + B[j]]++;

	for(auto i = 0; i != C.size(); ++i)
		for(auto j = 0; j != D.size(); ++j)
			map_CD[C[i] + D[j]]++;

	int sum = 0;
	for(auto i = map_AB.begin(); i != map_AB.end(); ++i)
		sum += (i -> second) * map_CD[(-1) * (i -> first)];

	return sum;
}

int main()
{
	vector<int> A = {1, 2};
	vector<int> B = {-2, -1};
	vector<int> C = {-1, 2};
	vector<int> D = {0, 2};
	cout << fourSumCount(A, B, C, D) << endl;

	return 0;
}
