#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// all permutation



vector<int> findAnagrams(string s, string p)
{
  vector<int> res;
  if(s.empty() || p.empty() || s.size() < p.size()) return res;
  unsigned int p_s = 0;

  for(auto i = 0; i != p.size(); ++i)
      p_s += (1 << (p[i] - 'a'));

  int len = p.size();
  map<unsigned int, vector<int>> map_n;

  for(auto i = 0; i <= s.size() - len; ++i)
  {
  	 string str = s.substr(i, len);
     unsigned int str_s = 0;

     for(auto j = 0; j != str.size(); ++j)
         str_s += (1 << (str[j] - 'a'));

     map_n[str_s].push_back(i);
  }

  return map_n[p_s];
}

int main()
{
	string s = "abab", p = "ab";
	vector<int> ps = findAnagrams(s, p);

	for(const auto& i : ps)
		cout << "i : " << i << endl;
	return 0;
}

