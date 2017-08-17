#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangleNumber(vector<int>& nums)
{
	int idx = 0;
	sort(nums.begin(), nums.end());

	for(auto i = 0; i < nums.size(); ++i)
		for(auto j = i + 1; j < nums.size(); ++j)
			for(auto k = j + 1; k < nums.size(); ++k)
				if(nums[i] + nums[j] > nums[k]) idx++;

	return idx;
}

int main()
{
   vector<int> nums = {2, 2, 3, 4};
   cout << triangleNumber(nums) << endl;
   return 0;
}