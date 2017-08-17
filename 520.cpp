#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool detectCapitalUse(string word) 
{
 // all zero, or no zero or one zero
 vector<int> res(word.size(), 0);
 for(auto i = 0; i < word.size(); ++i)
    if(word[i] < 97) res[i] = 1;

 int one_num = accumulate(res.begin(), res.end(), 0);
 if(word.size() == one_num)
 	return true;
 if(0 == one_num) return true;
 if(res[0] == 1 && one_num == 1) return true;
 return false;
}

int main()
{
	string str = "NBa";
	cout << detectCapitalUse(str) << endl;
	return 0;
}
