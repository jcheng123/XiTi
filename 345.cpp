#include <iostream>
#include <set>
#include <vector>

using namespace std;

string reverseVowels(string s)
{
   vector<int> loc;
   vector<char> vowel_unsort;

   for(auto i = 0; i != s.size(); ++i)
   {
     if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
        ||  s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
     {
       vowel_unsort.emplace_back(s[i]);
       loc.push_back(i);
     }
   }

   size_t idx = 0;
   for(auto i = vowel_unsort.rbegin(); i != vowel_unsort.rend(); ++i)
   {
      s[loc[idx]] =  (*i);
      idx++;
   }

   return s;
}

int main()
{
  cout << reverseVowels("leetcode") << endl;
  string s = "nanjing";
  return 0;
}
