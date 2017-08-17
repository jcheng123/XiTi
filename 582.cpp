#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) 
{
    queue<int> pro;
    pro.push(kill);
    vector<int> res;
    map<int, vector<int>> map_n;

    for(auto i = 0; i != ppid.size(); ++i)
    	map_n[ppid[i]].push_back(pid[i]);

    while(!pro.empty())
    {
    	int tmp = pro.front();
    	res.push_back(tmp);
    	pro.pop();

    	 for(auto i = 0; i != map_n[tmp].size(); ++i)
    	 	pro.push(map_n[tmp][i]);
    	
    }

    return res;
}

int main()
{
	vector<int> pid = {1, 3, 10, 5};
	vector<int> ppid = {3, 0, 5, 3};
	int kill = 5;
	vector<int> res = killProcess(pid, ppid, kill);
	for(const auto& i : res)
		cout << i << endl;
	return 0;
}