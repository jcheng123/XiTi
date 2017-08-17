#include <iostream>S
#include <vector>

using namespace std;

int fDuplicate(vector<int>& nums, int s, int e) // [s, e)
{
	if(e <= s || e - s == 1) return -1;
	int mid = (s + e)/2;
	auto i = s;

	int low = fDuplicate(nums, s, mid);
	int high = fDuplicate(nums, mid, e);


	if(low != -1) return low;
	if(high != -1) return high;

	if(low == -1 && high == -1) 
	{
       for(; i < mid; ++i)
       	  for(auto j = mid; j < e; ++j)
       	  {
       	  	 if(nums[i] == nums[j]) return nums[i];
       	  	
       	  }
	}

	return -1;
}

int findDuplicate(vector<int>& nums)
{
	return fDuplicate(nums, 0, nums.size());
}


int main()
{
	vector<int> nums = {1, 1, 2};
	cout << "result : " << findDuplicate(nums) << endl;
	return 0;
}