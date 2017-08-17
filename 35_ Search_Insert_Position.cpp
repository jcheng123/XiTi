#include <iostream>
#include <vector>

int searchInsert(vector<int>& nums, int target)
{
    int start = 0, end = (int)nums.size() - 1;
    int mid;

    while(start < end)
    {
      mid = (start + end)/2;
      if(nums[mid] > target) end = mid;
      else if(nums[mid] < target) start = mid;
           else return mid;
    }
    return mid;
}

int main()
{
  vector<int> nums = {3,7,10,12,90,189};
  int target = 20;
  cout << searchInsert(nums, target) << endl;
  return 0;
}
