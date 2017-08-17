#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>> res;
	if(root == NULL)
	{
		return res;
	}

	if(root -> left == NULL && root -> right == NULL)
	{
		if(root -> val == sum)
		{
			res.push_back(vector<int>(1, sum));
		}
		return res;
	}

	vector<vector<int>> le;
	if(root -> left != NULL) le = pathSum(root -> left, sum - (root -> val));
	vector<vector<int>> rig;
	if(root -> right != NULL) rig = pathSum(root -> right, sum - (root -> val));
    
    for(auto i = 0; i != le.size(); ++i)
    	le[i].insert(le[i].begin(), (root -> val));

    for(auto j = 0; j != rig.size(); ++j)
    	rig[j].insert(rig[j].begin(), (root -> val));
    
	res.insert(res.end(), le.begin(), le.end());
	res.insert(res.end(), rig.begin(), rig.end());

	return res;  
}	