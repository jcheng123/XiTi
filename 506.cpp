#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> findRelativeRanks(vector<int>& nums)
{
	vector<int> rank(nums.size());

	for(auto i = 0; i != rank.size(); ++i)
		rank[i] = i + 1;

	
}