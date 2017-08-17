#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int start = 0, end = (int)nums.size() - 1; /* [start, end] */
    int mid;

    while(start <= end)
    {
      mid = (start + end)/2;
      if(nums[mid] > target) end = mid - 1;
      else if(nums[mid] < target) start = mid + 1;
          else return mid;
    }
    if(nums[mid] < target) return (mid + 1);
    return mid;
}

int main(int argc, char* argv[])
{
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(7);
  nums.push_back(10);
  nums.push_back(12);
  nums.push_back(90);
  nums.push_back(189);
  cout << searchInsert(nums, atoi(argv[1])) << endl;
  return 0;
}
