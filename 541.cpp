#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string rStr(string s, int start, int end)
{
	while(start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;
}

string reverseStr(string s, int k)
{
	if(s.empty()) return s;
	int idx = 0;
	while(idx < s.size() && idx + k - 1 < s.size())
	{
		s = rStr(s, idx, idx + k - 1);
		idx += 2 * k;
	}

	if(s.size() % (2 * k) < k) s = rStr(s, s.size() - s.size() % (2 * k), s.size() - 1);
    return s;
}

int main()
{
	string s = "abcdefg";
	int k = 2;
	cout << reverseStr(s, k) << endl;
	return 0;
}