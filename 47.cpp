#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> pUnique(vector<int>& nums, int ord)
{ // [0...ord]
  vector<vector<int>> r;

  if(nums.empty()) return r;
  vector<int> tmp;
  if(ord == 0)
  {
  	tmp.push_back(nums[0]);
  	r.push_back(tmp);
  	return r;
  }
  if(ord > 0)
  {
  	  vector<vector<int>> res = pUnique(nums, ord - 1);
  	  for(auto i = 0; i != res.size(); ++i)
  		for(auto j = 0; j <= res[i].size(); ++j)
        {
        	tmp = res[i];
  			tmp.insert(tmp.begin() + j, nums[ord]);
  			r.push_back(tmp);
        }
  }
  return r;
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
     vector<vector<int>> res = pUnique(nums, nums.size() - 1);
     return res;
}
 
int main()
{
	vector<int> rt = {1, 2, 3};
	vector<vector<int>> rR = permuteUnique(rt);
	for(const auto& i : rR)
	{
		for(const auto& j : i)
			cout << j << "\t";
		cout << endl;
	}
	return 0;
}
