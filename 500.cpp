#include <iostream>
#include <map>
#include <vector>

using namespace std;


vector<string> findWords(vector<string>& words) 
{
	map<int, string> row;
	vector<string> s;

    row[0] = "QqWwEeRrTtYyUuIiOoPp";
    row[1] = "AaSsDdFfGgHhJjKkLl";
    row[2] = "ZzXxCcVvBbNnMm";

    map<char, int> res;
    for(auto i = row.begin(); i != row.end(); ++i)
    {
    	auto str = i -> second;
    	for(auto j = 0; j != str.size(); ++j)
    		res[str[j]] = i -> first;
    }

    for(auto i = 0; i != words.size(); ++i)
    {
        auto j = 1;
    	for(; j < words[i].size(); ++j)
    		if(res[words[i][j]] != res[words[i][0]])
    			break;

    	if(j == words[i].size()) s.push_back(words[i]);
    }

    return s;
}

int main()
{
	vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
	vector<string> str = findWords(words);
	for(auto i : str)
		cout << i << endl;
	return 0;
}


