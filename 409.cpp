#include <iostream>
#include <string>
#include <map>

using namespace std;

int longestPalindrome(string s)
{
	if(s.empty()) return 0;
	map<char, int> str;
	int len = 0;
	for(auto i = 0; i != s.size(); ++i)
		str[s[i]] ++;

    for(auto j = str.begin(); j != str.end(); ++j)
           if((j -> second) % 2 == 1) len++;    
    if(len >= 1) return (s.size() - len + 1);
    return (s.size() - len);
}

int main()
{
	string str = "bananas";
	cout << longestPalindrome(str) << endl;
	return 0;
}
