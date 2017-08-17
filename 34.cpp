#include <iostream> 
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> sRange(vector<int>& nums, int s, int e, int target) //[s, e)
{
	 vector<int> res;
	 if(nums.empty() || s >= e) 
	 	{ 
	 		res.push_back(-1); 
	 		res.push_back(-1); 
	 		return res;
	 	}

	 if(e - s == 1) 
	 	{
	 		if(nums[s] == target)
	 		{
		 		res.push_back(s);
		 		res.push_back(s);
	 	    }
	 	    else 
	 	    {
	 	    	res.push_back(-1);
	 	    	res.push_back(-1);
	 	    }

	 		return res;
	 	}

     int mid = (s + e) / 2;

     vector<int> low  = sRange(nums, s, mid, target);
     

     vector<int> high = sRange(nums, mid, e, target);


     if(low[0] == -1)
     {
         return high;
     }

     if(high[0] == -1)
     {
     	return low;
     }

     if(low[0] != -1 && high[0] != -1)
     {
     	res.push_back(low[0]);
     	res.push_back(high[1]);
     }

     return res;

}

vector<int> searchRange(vector<int>& nums, int target)
{
         return sRange(nums, 0, nums.size(), target);
}

int main(int argc, char** argv)
{
	vector<int> nums = {7,7,8,8,9};
	int target = atoi(argv[1]);
	//int target = 8;

	vector<int> res = searchRange(nums, target);
	for(const auto& i : res)
		cout << "index : " << i << endl;
	return 0;
}