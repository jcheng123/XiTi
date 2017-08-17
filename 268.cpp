#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
       // the len of nums is n
       int res = 0;
       for(auto i = 0; i != nums.size(); ++i)
       {
           res ^= nums[i];
           res ^= i;
       }
       int n = nums.size();
       res ^= n;
       return res;
}

int main()
{
  vector<int> num = {0, 2, 3, 4};
  cout << missingNumber(num) << endl;
  return 0;
}
