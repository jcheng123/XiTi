#include <iostream>
#include <string>
#include <map>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    map<char, int> map_1;
    map<char, int> map_2;

    for(auto i = 0; i != ransomNote.size(); ++i)
    	map_1[ransomNote[i]]++;

    for(auto j = 0; j != magazine.size(); ++j)
    	map_2[magazine[j]]++;

    for(auto i = map_1.begin(); i != map_1.end(); ++i)
    {
    	char ps = i -> first;
    	if(map_1[ps] <= map_2[ps]) continue;
    	else return false;
    }
    return true;
}

int main()
{
	string ransomNote = "aa", magazine = "aab";
	cout << canConstruct(ransomNote, magazine) << endl;
	return 0;
}