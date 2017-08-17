#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) 
{
	if(nums.size() == 0) return -1;
	if(nums.size() == 1) return 0;
	
	int s = 0, e = nums.size() - 1; // [s, e]
	int mid;


	while(s < e)
	{
		if(nums[s] > nums[s + 1]) return s;
	    if(nums[e] > nums[e - 1]) return e;

		mid = (s + e)/2;
		if(nums[mid] > nums[mid - 1]) s = mid;
		else e = mid;
	}
	return mid;
}

int main()
{
	vector<int> nums = {11, 12, 8, 120, 9};
	cout << findPeakElement(nums) << endl;
	return 0;
}
