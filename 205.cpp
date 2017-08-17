#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool isIsomorphic(string s, string t) 
{
	if(s.size() != t.size())   return false;
	if(s.empty() && t.empty()) return true;

	map<char, set<char>> map_v;
	map<char, set<char>> map_u;

    for(auto i = 0; i != s.size(); ++i)
    {
     	map_v[s[i]].insert(t[i]);
     	map_u[t[i]].insert(s[i]);
    }

    for(const auto& i : map_v)
    {
    	if(i.second.size() != 1) 
    		return false;
    }

    for(const auto& j : map_u)
    {
    	if(j.second.size() != 1)
    		return false;
    }

    return true;

}

int main(int argc, char** argv)
{
	string s = argv[1];
	string t = argv[2];

	cout << isIsomorphic(s, t) << endl;
    // isIsomorphic(s, t);
	return 0;
}
