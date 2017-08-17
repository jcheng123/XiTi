#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> getPer(int n)
{
	vector<vector<string>> str(n + 1);
	vector<string> res;

    str[n].push_back(to_string(n));

    for(int i = n - 1; i >= 1; --i)
    {
    	for(auto j = 0; j != str[i + 1].size(); ++j)
    	{
    		string s = str[i + 1][j];
    		for(auto l = 0; l <= s.size(); ++l)
    		{
    			string s_tmp = s.substr(0, l) + to_string(i) + s.substr(l, s.size() - l);
    			res.push_back(s_tmp);
    		}
    	}
    } 

    return res;  
}

int jie_cheng(int n)
{
	if(n == 1 || n == 0) return 1;
	return n * jie_cheng(n - 1);
} 

string getPermutation(int n, int k) 
{
	if(k > jie_cheng(n)) 
	{
		string stp = "";
		return stp;
	}

    vector<string> r = getPer(n);
    
	return r[k - 1];
}


int main()
{
	int n = 3;
	int k = 3;
	string str = getPermutation(n, k);
	for(auto i = 0; i != str.size(); ++i)
		cout << str << endl;

	return 0;
}