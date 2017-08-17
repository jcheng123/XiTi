#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
	vector<int> res(nums.size(), 0);
	res[0] = nums[0];

	for(auto i = 1; i != nums.size(); ++i)
	{
         res[i] = (res[i - 1] >= 0 ? res[i - 1] : 0) + nums[i];
	}

	int num = res[0];

	for(auto j = 1; j != res.size(); ++j)
		num = max(num, res[j]);
	return num;
}

int main()
{
	vector<int> nums = {3, 4, 6, -4, 10, -120};
    cout << maxSubArray(nums) << endl;
    return 0;
}