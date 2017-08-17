#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
  int i = 0;
  int j = 0;
  int idx = 0;
  while(i < m && n == 0)
  {
      nums1[i + m] = nums1[i];
      i++;
  }

  while(j < n && m == 0)
  {
      nums1[j + m] = nums2[j];
      j++;
  }

  while(i < m && j < n)
  {
    if(nums1[i] < nums2[j]){ nums1[idx + m] = nums1[i]; ++i; }
    else { nums1[idx + m] = nums2[j]; ++j; }
    idx++;
  }

  while(i < m)
  {
    nums1[idx + m] = nums1[i++];
    idx++;
  }

  while(j < n)
  {
    nums1[idx + m] = nums2[j++];
    idx++;
  }

  nums1.erase(nums1.begin(), nums1.begin() + m);
}

int main()
{
  vector<int> s = {1};
  vector<int> t = {};
  s.resize(10);
  merge(s, 1, t, 0);
  for(const auto& i : s)
     cout << i << endl;
  return 0;
}
