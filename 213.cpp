#include <iostream>
#include <vector>

using namespace std;

int robber(vector<int>& nums, int s, int e) //[s, e]
{
	vector<int> money(e - s + 1, 0);
	money[0] = nums[s];
	money[1] = max(nums[s], nums[s + 1]);

	for(auto i = s + 2; i <= e; ++i)
	{
      money[i - s] = max(money[i - 1 - s], money[i - 2 - s] + nums[i]);
	}	

	return money[e - s];
}

int rob(vector<int>& nums)
{
	int x = robber(nums, 0, nums.size() - 2);
	int y = robber(nums, 1, nums.size() - 1);
	return max(x, y);
}

int main()
{
	vector<int> num = {1, 1, 1};
	cout << rob(num) << endl;
	return 0;
}