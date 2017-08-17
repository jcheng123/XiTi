#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    if(nums.empty())  return 0;

    vector<int> res(nums.size(), 0);
    vector<int> visited(nums.size(), 0);
    res[0] = nums[0];
    res[1] = max(nums[1], nums[0]);

    for(auto i = 1; i < nums.size() - 1; ++i)
    {
      // res[i + 1] = (res[i] - nums[i] + max(nums[i], nums[i + 1])) * visited[i]
      //            + (res[i] + nums[i + 1])*(1 - visited[i]);
      // visited[i + 1] = 1;
      int max_money = nums[0];
      for(auto j = 0; j < i; ++j)
      {
        max_money = max(max_money, res[j]);
      }
      res[i + 1] = max(max_money + nums[i + 1], res[i]);
    }
    for(const auto& i:res)
       cout <<"robbed number is : " << i << endl;
    return res[nums.size() - 1];

}

int main()
{
 vector<int> nums = {900, 306, 100, 32, 23};
 cout << rob(nums) << endl;
 return 0;
}
