#include <string>
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> cN(string a)
{
	string s1 = "";
	int real1 = 0, img1 = 0;
	pair<int, int> res;

	int i = 0, j = 0;
	for(; i != a.size(); ++i)
	{
		if(a[i] != '+') s1 += a[i];
		else { real1 = atoi(s1.c_str()); s1.clear(); break; }

	}

    ++i;
	for(; i != a.size(); ++i)
	{
		if(a[i] != 'i') s1 += a[i];
		else { img1 = atoi(s1.c_str()); break;}
	}

	res = {real1, img1};
	return res;
}

string complexNumberMultiply(string a, string b) 
{
	pair<int, int> a_res = cN(a);
	pair<int, int> b_res = cN(b);
    
    int real = a_res.first * b_res.first - a_res.second * b_res.second;
    int img  = a_res.first * b_res.second + a_res.second * b_res.first;
    string s = to_string(real) + "+" + to_string(img) + "i";
    return s;
}

int main()
{
	string a = "1+1i";
	string b = "1+1i";
	cout << complexNumberMultiply(a, b) << endl;
    return 0;
}
	
    


