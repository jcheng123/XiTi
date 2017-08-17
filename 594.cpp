#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int x, int y)
{
	return (x > y);
}

int findLHS(vector<int>& nums) 
{
   if(nums.empty()) return 0;

   map<int, int> res;
   int max_l = 0;

   for(auto i = 0; i != nums.size(); ++i)
   {
   	   	res[nums[i]] ++;
   }

   for(auto i: res)
   {
       if(res[i.first + 1] != 0) 
       	 max_l = max(max_l, res[i.first] + res[i.first + 1]);
       else res.erase(i.first + 1); 
   }



   return max_l;


}

int main()
{
	vector<int> nums = {1,3,2,2};
	int x = findLHS(nums);
	cout << x << endl;
	return 0;
}