#include <iostream>
#include <string>

using namespace std;

int countSegments(string s)
{
	int num = 0;

	for(auto i = 1; i != s.size(); ++i)
	{
		if(s[i] == ' ' && s[i - 1] != ' ') num++;
	}

	if(s[s.size() - 1] != ' ') num++;

    

	return num;
}

int main()
{
	string s = "Hello, my name is John";
	cout << countSegments(s) << endl;
	return 0;
}