#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int findMaxLength(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 0) return 0;

	vector<int> one(n, 0);
	vector<int> zero(n, 0);
	map<int, int> map_n; 
	// map_n[i] : key is the subarray's number difference between 0s and 1s. 
	//            value is the subarray's end point.
	
	if(nums[0] == 1) one[0]  = 1;
	if(nums[0] == 0) zero[0] = 1;

	map_n[one[0] - zero[0]] = 0;

	int num = 0;
	for(auto i = 1; i < n; ++i)
	{
		if(nums[i] == 0) 
		{
			one[i]  = one[i - 1];
			zero[i] = zero[i - 1] + 1;
		}
		else 
		{
            one[i]  = one[i - 1] + 1;
            zero[i] = zero[i - 1];
		}
		if(one[i] == zero[i]) num = max(num, i + 1);
		else 
        {
        	if(map_n.count(one[i] - zero[i]) == 0) map_n[one[i] - zero[i]] = i;
        	else num = max(num, i - map_n[one[i] - zero[i]]);
        }

	}

	return num;
}


int main()
{
	vector<int> num = {0, 0, 1};
	cout << findMaxLength(num) << endl;
	return 0;
}
