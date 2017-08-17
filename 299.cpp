#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string getHint(string secret, string guess) 
{
	int bull_num = 0;
	int cow_num  = 0;
	string s = secret;
	string g = guess;

	for(auto i = 0; i != g.size(); ++i)
		if(s[i] == g[i]) 
		{
			g[i] = 'A';
			s[i] = 'A';
		}

	for(auto i = 0; i != guess.size(); ++i)
	{
		auto iter = find(s.begin(), s.end(), g[i]);
		if(g[i] != 'A' && iter != s.end())
		{
			g[i] = 'B';
			*iter = 'B';
		}
	}

	for(auto i = 0; i != g.size(); ++i)
	{
		if(g[i] == 'A') bull_num++;
		if(g[i] == 'B') cow_num ++;
	}

	string st = to_string(bull_num) + "A" + to_string(cow_num) + "B";
	return st;
}

int main()
{
	string sec = "1807", gue = "7810";
	cout << getHint(sec, gue) << endl;
	return 0;
}
