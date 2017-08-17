#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	if(k > n) return res;
    if(n <= 0 || k <= 0) return res;
    if(k == 1)
    {
    	vector<int> tmp;
    	for(auto i = 1; i <= n; ++i)
    	{
    		tmp.push_back(i);
    		res.push_back(tmp);
    		tmp.clear();
    	}
    	return res;
    }

    res = combine(n - 1, k - 1);
    for(auto i = 0; i != res.size(); ++i)
    {
    	res[i].push_back(n);
    }

    
    vector<vector<int>> r = combine(n - 1, k);
    res.insert(res.end(), r.begin(), r.end());

    return res;
} 

int main()
{
	int n = 2, k = 1;
	vector<vector<int>> res = combine(n, k);
	for(const auto& i : res)
    {
    	for(const auto& j : i)
    		cout << j << "\t";
    	cout << endl;
    }
    return 0;
}