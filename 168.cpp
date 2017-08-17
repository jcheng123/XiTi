#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convertToTitle(int n)
{

    vector<char> letter = {'Z', 'A', 'B', 'C', 'D', 'E', 'F',
                         'G', 'H', 'I', 'J', 'K', 'L',
                         'M', 'N', 'O', 'P', 'Q', 'R',
                          'S', 'T', 'U', 'V', 'W', 'X',
                          'Y'};
    string s ="";

    while(n)
    {
       s += letter[(n % 26)];
       if(n % 26 == 0) n = n/26 - 1;
       else n = n / 26;
    }

    string res = "";
    for(auto i = s.rbegin(); i != s.rend(); ++i)
          res += (*i);
    return res;
}


int main()
{
  cout << convertToTitle(52) << endl;
  return 0;
}
