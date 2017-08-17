#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
	vector<int> letter_s(26, 0);
	vector<int> letter_t(26, 0);

	for(auto i = 0; i != s.size(); ++i)
		letter_s[s[i] - 'a']++;

	for(auto j = 0; j != t.size(); ++j)
		letter_t[t[j] - 'a'] ++;

	if(letter_t == letter_s) return true;
	return false;

}

int main()
{
	string s = "anagram", t = "nagaram";
	cout << isAnagram(s, t) << endl;
	return 0;
}