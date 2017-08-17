#include <iostream>
#include <string>

using namespace std;

bool checkRecord(string s)
{
	if(s.empty()) return false;
	int absent_num = 0;
	int late_num   = 0;
	int start = -1, e   = -1;

	for(auto i = 0; i != s.size(); ++i)
	{
        if(s[i] == 'A') absent_num++;
	}
	if(absent_num > 1) return false;

    if(s[0] == 'L')  start = 0;
	for(auto i = 1; i != s.size(); ++i)
	{
		if(s[i] == 'L' && s[i - 1] != 'L') start = i;
		if(i < s.size() - 1 && s[i + 1] != 'L' && s[i] == 'L') e = i;
		else if(i == s.size() - 1 && s[i] == 'L')  e = i;
		late_num = e - start + 1;
		// cout << late_num << endl; 
		if(late_num >= 3) return false; 
	}
	


	return true;
}

int main()
{
	string s = "ALL";
	cout << checkRecord(s) << endl;
	return 0;
 }