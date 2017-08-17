#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool repeatedSubstringPattern(string s)
{
   if(s.empty()) return false;
   int sublen = 1;
   while(sublen < s.size())
   {
   	 auto i = sublen;
   	 for(; i < s.size(); i = i + sublen)
   	 {
   	 	if(s.substr(i, sublen) == s.substr(i - sublen, sublen)) continue;
   	 	else break;
   	 }
   	 if(i == s.size()) return true;
   	 sublen++;
   }
   
   return false;

}

int main()
{
	string str = "abaababaab";
	cout << repeatedSubstringPattern(str) << endl;
	return 0;
}