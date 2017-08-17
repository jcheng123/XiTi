#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combineSum2(vector<int>& candidates, int start, int target) 
{
    vector<vector<int>> res;

    if(start >= candidates.size()) return res;
    if(target <= 0) return res;

    if(candidates[start] == target)
    {
    	res.push_back(vector<int>(1, target));
    }

	vector<vector<int>> r = combineSum2(candidates, start + 1, target);
	vector<vector<int>> l = combineSum2(candidates, start + 1, target - candidates[start]);
	
	for(auto& p : l)
	{
		     p.push_back(candidates[start]);
	}

	for(auto i = 0; i != r.size(); ++i)
	{
		sort(r[i].begin(), r[i].end());
		if(find(res.begin(), res.end(), r[i]) == res.end())
			res.push_back(r[i]);
	}

	for(auto j = 0; j != l.size(); ++j)
	{
		sort(l[j].begin(), l[j].end());
		if(find(res.begin(), res.end(), l[j]) == res.end())
			res.push_back(l[j]);
	}


	return res;
}

int main()
{
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	vector<vector<int>> R = combineSum2(candidates, 0, target);

	for(const auto& i : R)
	{
		for(const auto& j : i)
			cout << j << "\t";
		cout << endl;
	}

	return 0;
}
