#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int jinwei(char x, char y)
{
  if(x == '1' && y == '1') return 1;
  return 0;
}

int patoi(char x)
{
  if(x == '1') return 1;
  return 0;
}

string addBinary(string a, string b)
{

       int a_len = a.size(), b_len = b.size();
       int common_len = min(a_len, b_len);
       string s = "";
       int x = 0;
       int i = 0;
       for(; i != common_len; ++i)
       {
         int p = patoi(a[a_len - 1 - i]), q = patoi(b[b_len - 1 - i]);
         s += to_string((x + p + q) & 1);
         x = (x + p + q) >> 1;
       }

       for(; i < a_len; ++i)
       {
         int p = patoi(a[a_len - 1 - i]);
         s += to_string((x + p) & 1);
         x = (x + p) >> 1;
       }

       for(; i < b_len; ++i)
       {
         int q = patoi(b[b_len - 1 - i]);
         s += to_string((x + q) & 1);
         x = (x + q) >> 1;
       }

       if(x == 1) s += '1';
       string res;
       for(auto i = s.rbegin(); i != s.rend(); ++i)
            res +=(*i);
       return res;


}


int main()
{
  cout << addBinary("1111", "1111") << endl;
  cout << endl;
  return 0;
}
