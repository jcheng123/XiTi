#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool b_search(vector<int>& num, int val) // [s, e]
{  // assume that num is sorted 
   // for example, num = {1, 2}, val = 2;
     int s = 0, e = num.size() - 1;

     while(s <= e)
     {
     	 int mid = (s + e)/2;

         if(num[mid] == val) { num.erase(num.begin() + mid); return true;}
         if(num[mid] >  val) 
         {
         	e = mid - 1;
         } 
         if(num[mid] < val)
         {
         	s = mid + 1;
         }
     }

     return false;
}


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	int m = nums1.size(), n = nums2.size();
	vector<int> res;
    
    if(m > n)
    {
    	swap(nums1, nums2); // nums1 always is the shorter one.
    }

    sort(nums2.begin(), nums2.end());
    for(int i = nums1.size() - 1; i != -1; --i)
    {   
    	//cout << " value : " << nums1[i] << "\t" << "the value in nums2 ? " << (b_search(nums2, nums1[i]) ? "yes" : "no") << endl;
        if(b_search(nums2, nums1[i]))  
        {        
            res.push_back(nums1[i]); 
        }
    }

    return res;
}

int main()
{
	vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
	vector<int> res   = intersect(nums1, nums2);

	for(const auto& i : res)
	    cout << i << endl;

	return 0;
}
