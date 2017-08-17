#include <iostream>
#include <vector>

using namespace std;

int HammingDistance(int x, int y)
{
  int res = x ^ y;
  int n = 0;

  while(res)
  {
    res = res & (res - 1);
    n++;
  }
  return n;
}


int totalHammingDistance(vector<int>& nums) {
  int res = 0;
  for(auto i = 0; i < nums.size(); ++i)
       for(auto j = i + 1; j < nums.size(); ++j)
            res += HammingDistance(nums[i], nums[j]);

  return res;
}

int main()
{
  vector<int> nums = {4, 14, 2};
  cout << totalHammingDistance(nums) << endl;
  return 0;
}
