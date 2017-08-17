#include <iostream>
#include <cmath>
#include <string>

using namespace std;



int titleToNumber(string s)
{
	int n   = s.size() - 1;
	int res = 0;

    for(auto i = 0; i < s.size(); ++i)
    {
    	res += (s[i] - 'A' + 1)*pow(26, n - i);
    }

    return res;
}

int main()
{
	string s = "AA";
	cout << titleToNumber(s) << endl;
	return 0;
}