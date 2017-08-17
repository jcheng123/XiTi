#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int dirstUniqChar(string s)
{
   map<char, vector<int>> map_n;
   int idx = s.size();;

   for(auto i = 0; i != s.size(); ++i)
   	  map_n[s[i]].push_back(i);

   for(auto iter = map_n.begin(); iter != map_n.end(); ++iter)
   {
   	  int s_num = (iter -> second).size();
   	  if(s_num == 1) 
   	  {
          idx = min(idx, (iter-> second)[0]);
   	  }

   }

   if(idx == s.size()) return -1;
   return idx;
}

int main()
{
	string s = "loveleetcode";
	cout << dirstUniqChar(s) << endl;
	return 0;
}