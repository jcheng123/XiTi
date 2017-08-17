#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(string s) 
{
	for(int i = s.size() - 1; i >= 0; --i)
	{
		int res = s[i];
		if(res >= 65 && res <= 90) s[i] = s[i] + 32;
		if(res == '0' || res == '1' || res == '2' || res == '3'
			|| res == '4' || res == '5' || res == '6' || res == '7'
			|| res == '8' || res == '9') continue;
	    else if(s[i] < 97 || s[i] > 122) s.erase(s.begin() + i);
	}
	int st = 0, en = s.size() - 1;
    
    while(st <= en)
    {
    	if(s[st] == s[en])
    	{
    		st++;
    		en--;
    		continue;
    	}
    	else return false;
    }

    return true;
}

int main()
{
	cout << isPalindrome("0P") << endl;
	return 0;
}

