#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
   map<int, vector<size_t>> map_n;

   for(size_t i = 0; i != nums.size(); ++i)
   	   map_n[nums[i]].push_back(i);

   for(const auto& i : map_n)
   	   {
   	   	 vector<size_t> tmp = i.second;

   	   	 if(tmp.size() <= 1) continue;

         //sort(tmp.begin(), tmp.end());

         for(auto j = 0; j < tmp.size(); ++j)
         {
            if(tmp[j + 1] - tmp[j] <= k) return true;
         }
   	   }
   	   return false;
}

int main()
{
	vector<int> nums = {1, 1, 4, 1, 2};
	int k = 2;
	cout << containsNearbyDuplicate(nums, k) << endl;
	return 0;
}