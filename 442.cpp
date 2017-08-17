#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums)
{
    vector<int> res(nums.size(), 0);

    for(auto i = 0; i != nums.size(); ++i)
    {
      res[nums[i] - 1] ++;
    }

    for(auto i = nums.size() - 1; i != -1; --i)
    {
      if(res[i] <= 1) res.erase(res.begin() + i);
      else res[i] = i + 1;
    }

    return res;
}

int main()
{
  vector<int> nums = {4,3,2,7,8,2,3,1};
  vector<int> res  = findDuplicates(nums);
  for(const auto& i : res)
     cout << i << endl;
  return 0;
}
