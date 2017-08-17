vector<vector<int>> combineSum(vector<int>& candidates, int s, int target) 
{

	vector<vector<int>> res;
	if(s < 0 || s >= candidates.size()) return res;

	if(target <= 0)     return res;
	int targ = target;
	int k    = targ / candidates[s] + 1;



	for(auto j = 0; j < k; ++j)
	{
		vector<vector<int>> son = combineSum(candidates, s + 1, targ - j * candidates[s]);
		
		for(auto i = 0; i != son.size(); ++i)
		   for(auto t = 0; t != j; ++t)
			   son[i].push_back(candidates[s]);
        
		res.insert(res.end(), son.begin(), son.end());
    }

    

    if(targ % candidates[s] == 0)
    {
    	vector<int> tmp = vector<int>(k - 1, candidates[s]);
	    res.push_back(tmp);
	}
    
    return res;  
}


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> res = combineSum(candidates, 0, target);
    vector<int> del(res.size(), 0);
	for(auto tmp = res.begin(); tmp != res.end(); ++tmp)
	   for(auto iter = tmp + 1; iter != res.end(); ++iter) 
	   {
	   	 if((*iter) == (*tmp)) del[iter - res.begin()] = 1;
	   }

	for(int i = del.size() - 1; i != -1; --i)
    {
        if(del[i] == 1) res.erase(res.begin() + i);
    }

	return res;
    }
};