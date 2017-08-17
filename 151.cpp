#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseWords(string &s)
{
	if(!s.empty())
	{
		if(count(s.begin(), s.end(), ' ') == s.size()) s.clear();

		
		while(s[0] == ' ') s.erase(s.begin());
		while(s[s.size() - 1] == ' ') s.erase(s.end() - 1);
		for(auto i = s.size() - 1; i >= 1; --i)
		{
           if(s[i] ==' ' && s[i - 1] == ' ') s.erase(s.begin() + i);
		}

		int j = s.size() - 1;
		int i = 0;


		while(i < j)
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}


		
        int kh;
        for(auto k = 0; k < s.size(); ++k)
        {   
           if(k == 0) kh = k;
           else if(s[k] != ' ' && s[k - 1] == ' ') kh = k;
           if(s[k] == ' ' || k == s.size() - 1)
           {
           	 int i = kh;
           	 if(s[k] == ' ') j = k - 1;
           	 else j = k;
           	 while(i < j)
           	 {
           	 	swap(s[i], s[j]);
           	 	i++;
           	 	j--;
           	 }
           }
        }


    }

}

int main()
{
	string s = "   a   b ";
	reverseWords(s);
	cout << s << endl;	
	return 0;
}