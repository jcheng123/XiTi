#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;



vector<vector<int>> subsetWithDup(vector<int>& nums)
{ // bingbi s
  deque<vector<int>> A;
  vector<vector<int>> B;
  A.push_back(nums);
  
  while(!A.empty())
  {
  	vector<int> tmp = A.front();
    B.push_back(tmp);
  	A.pop_front();

  	for(auto i = tmp.begin(); i != tmp.end(); ++i)
  	{
       vector<int> r;
       r.insert(r.end(), tmp.begin(), i);
       r.insert(r.end(), i + 1, tmp.end());
       sort(r.begin(), r.end());
       if(find(A.begin(), A.end(), r) == A.end()) A.push_back(r);   
    }

  }

   return B;
}

int main()
{
	vector<int> nums = {4,4,4,1,4};
	vector<vector<int>> res = subsetWithDup(nums);
	cout << "subset number : " << res.size() << endl;
	for(auto i : res)
	{
		for(auto j : i)
		{
			cout << "j : " << j << "\t";
		}
		cout << endl;
	}
    return 0;
}




