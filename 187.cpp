#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
      map<string, int> substr;
      vector<string> vec;

      for(auto i = 0; i <= s.size() - 10; ++i)
      	substr[s.substr(i, 10)]++;

      for(auto j = substr.begin(); j != substr.end(); ++j)
      	if(j -> second > 1) vec.push_back(j -> first);

      return vec;
  }