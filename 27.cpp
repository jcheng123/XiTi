#include <iostream>
#include <vector>

using namespace std;

 int removeElement(vector<int>& nums, int val) 
 {
       for(int i = nums.size() - 1; i != -1; --i)
          if(nums[i] == val)  nums.erase(nums.begin() + i);
       int len = nums.size();
       return len;
 }

 int main()
 {
 	vector<int> nums = {2, 2, 3, 3};
 	int val = 3;
 	cout << removeElement(nums, val) << endl;
 	return 0;
 }