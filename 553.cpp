#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

  string optimalDivision(vector<int>& nums) {
    string s = "";
    if(nums.size() == 1) return to_string(nums[0]);
    if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);

	s = to_string(nums[0]) + '/' + '(';
	for(auto i = 1; i < nums.size(); ++i)
		if(i != nums.size() - 1) s += to_string(nums[i]) + '/';
	    else s += to_string(nums[i]) + ')';

	return s;
    }

int main()
{
	vector<int> nums = {6, 2, 3, 4, 5};
	cout << optimalDivision(nums) << endl;
	return 0;
}