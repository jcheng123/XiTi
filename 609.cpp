#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> findDuplicate(vector<string>& paths)
{
	map<string, vector<string>> map_n;
	vector<vector<string>> res;
	for(auto i = 0; i != paths.size(); ++i)
	{
       string ans = paths[i]; // ans is the i-th paths and file name
       vector<string> sub;
       string str;
       string file;
       string content;
       auto j = 0;
       for(; j != ans.size(); ++j)
       {
           if(ans[j] != ' ') str += ans[j];
           else 
           {
           	 sub.push_back(str);
           	 str = "";
           }
       }

       if(j == ans.size()) 
       {
       	sub.push_back(str);
        str = "";
       }

       for(auto k = 1; k < sub.size(); ++k)
       {  // sub[k] : *****.txt(*****)
       	  int idx = 0;
       	  for(auto t = 0; t < sub[k].size(); ++t)
       	  {
       	  	if(sub[k][t] != '(' )
       	  	{
       	  		if(idx == 0) file += sub[k][t];
       	  		if(idx == 1 && sub[k][t] != ')') content += sub[k][t];
       	  	}
       	  	else
       	  	{
       	  		idx = 1;
       	  	}
       	  }
       	  map_n[content].push_back(sub[0] + '/' + file);
       	  file = "";
       	  content = "";
       }
   }
   
   for(auto i = map_n.begin(); i != map_n.end(); ++i)
   {
   	   vector<string> Str = i -> second;
   	   if(Str.size() >= 2) res.push_back(Str);
   }


   return res;
}

int main()
{
	vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> r = findDuplicate(paths);

    for(const auto& i : r)
    {
    	for(const auto& j : i)
    		cout << j << "\t";
    	cout << endl;
    }

    return 0;
}