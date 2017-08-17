#include <iostream>
#include <vector>

using namespace std;


void rotate(vector<int>& nums, int k)
{
      int n = nums.size();
      k = k % n;
      int res = n - k;
      nums.insert(nums.end(), nums.begin(), nums.end() - k);
      for(const auto& i : nums)
         cout << " i : " << i << endl;
      nums.erase(nums.begin(), nums.begin() + res);

}

  int main()
  {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "the address of k : " << &k << endl;
    rotate(nums, k);
    for(const auto& i : nums)
       cout << i << endl;
    return 0;
  }
