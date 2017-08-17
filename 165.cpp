#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int compareVersion(string version1, string version2)
{
	if(version1.size() == 0 && version2.size() == 0) return 0;
	if(version1.size() == 0 && version2.size() > 0)  return -1;
	if(version1.size() > 0  && version2.size() == 0) return 1; 
	vector<int> str1;
	vector<int> str2;

	string str = "";
	for(auto i = 0; i != version1.size(); ++i)
	{
        if(version1[i] != '.')  str += version1[i];
        else { str1.push_back(atoi(str.c_str())); str = ""; }
	}

	str1.push_back(atoi(str.c_str()));
	str = "";

	for(auto i = 0; i != version2.size(); ++i)
	{
        if(version2[i] != '.')  str += version2[i];
        else { str2.push_back(atoi(str.c_str())); str = ""; }
	}

	cout << "str2.size() : " << str2.size() << endl;

	for(auto i = 0; i != str1.size(); ++i)
		cout << "version1 : " << str1[i] << endl;

	for(auto j = 0; j != str2.size(); ++j)
		cout << "version2 : " << str2[j] << endl;

	str2.push_back(atoi(str.c_str()));
	str = "";
  
	int i = 0;
	while(i < str1.size() && i < str2.size())
	{
		if(str1[i] == str2[i]) 
		{
			i++;
		}
		else if(str1[i] < str2[i]) return -1;
		else return 1;
	}
    
	while(i < str2.size())
	{
      if(str2[i] > 0) return -1;
      ++i;
	}
	while(i < str1.size()) 
	{
	  if(str1[i] > 0) return 1;
	  ++i;
	}
	return 0;
}

int main()
{
	string ver1 = "1.0", ver2 = "1";
	cout << compareVersion(ver1, ver2) << endl;
	return 0;
}