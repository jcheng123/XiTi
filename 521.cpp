#include <iostream>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

int findLUSlength(string a, string b) 
{
    deque<string> store;
    store.push_back(a);

    while(!store.empty())
    {
      string tmp = store.front();
      auto ptr = strstr(b.c_str(), tmp.c_str());
      if(ptr) return (a.size() - tmp.size()) == 0 ? -1 : (a.size() - tmp.size());
      string s = "";
      store.pop_front();
      for(auto i = tmp.begin(); i != tmp.end(); ++i)
      {
          s.insert(s.end(), tmp.begin(), i);
          s.insert(s.end(), i + 1, tmp.end());
          store.push_back(s);
      }
    }
    return -1;
}

int main()
{
	string a = "aaa";
	string b = "aaa";
	cout << findLUSlength(a, b) << endl;
	return 0;
}
