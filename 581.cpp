#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) 
{
    if(nums.empty()) return 0;
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    int start = 0;
    int idx   = 0;
    int end   = 0;
    
    for(int i = 0; i != tmp.size(); ++i)
    {
        if(idx == 0 && tmp[i] != nums[i]) { start = i; idx ++; }
        if(idx == 1 && tmp[i] != nums[i]) { end   = i; }
    }
    
    return end - start + 1;
          
}

int main()
{
  vector<int> num = {2, 6, 4, 8, 10, 9, 15};
  cout << findUnsortedSubarray(num) << endl;
  return 0;
}