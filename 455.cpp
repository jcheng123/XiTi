#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    int i = 0;
    for(int  j = 0; i < g.size() && j < s.size(); ++j)
    {
      if(g[i]<=s[j]) i ++;
    }
    return i;
}

int main()
{
  vector<int> g = {1, 2};
  vector<int> s = {1, 2, 3};
  cout << findContentChildren(g, s) << endl;
  return 0;
}
