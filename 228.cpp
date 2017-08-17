#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> Str;
	if(nums.empty()) return Str;
	if(nums.size() == 1) 
    {
   	    Str.push_back(to_string(nums[0]));
   	    return Str;
    }
	int s = 0, e = 0;
	string str;

	for(auto i = 1; i != nums.size() ; ++i)
	{
		unsigned int tmp = nums[i] - nums[i - 1];
		if(tmp > 1)  
		{ 

			e = i - 1;
			if(s == e) 
			{
				str = to_string(nums[s]);
				Str.push_back(str);
				str = "";
			}
			else 
			{
				str += to_string(nums[s]);
				str += "->";
				str += to_string(nums[e]);
				Str.push_back(str);
				str = "";
		    }
			s = i;
		}
	

		if(i == nums.size() - 1)
		{
			if(s == i)
			{
				str = to_string(nums[s]);
				Str.push_back(str);
				str = "";
			}
			else 
			{
				str += to_string(nums[s]);
                str += "->";
                str += to_string(nums[i]);
                Str.push_back(str);
                str = "";
			}
		}
   	}
   	return Str;
}

int main()
{
	vector<int> nums = {-2, -1, 1, 2, 2147483646, 2147483647};
	vector<string> str = summaryRanges(nums);
	for(auto i : str) 
		cout << i << endl;
	return 0;
}