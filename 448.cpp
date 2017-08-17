#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
   vector<int> res(nums.size(), 0);
   for(auto i = 0; i != nums.size(); ++i)
   {
     res[nums[i] - 1] = nums[i];
   }

   for(auto i = res.size() - 1; i != -1 ; --i)
   {
      if(res[i] == i + 1) res.erase(res.begin() + i);
      else res[i] = i + 1;
   }

   return res;
 }

 int main()
 {
   vector<int> num = {4,3,2,7,8,2,3,1,8,12,1,7};
   vector<int> res = findDisappearedNumbers(num);
   for(auto i : res)
      cout << i << endl;
   return 0;
 }
