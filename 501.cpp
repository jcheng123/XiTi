#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> findM(TreeNode* root, int& fre) 
{ 
	vector<int> res;
    if(root == NULL)
    {
    	fre = 0;
    	return res;
    }

    if(root -> left == NULL && root -> right == NULL)
    {
    	fre = 1;
    	res.push_back(root -> val);
    	return res;
    }

    int l = 0, r = 0;
    vector<int> lef = findM(root -> left, l);
    vector<int> rig = findM(root -> right, r);

    if(l >= r + 2) 
    {
    	if(find(lef.begin(), lef.end(), root -> val) == lef.end())
           return lef;
        else
        {
        	res.push_back(root -> val);
        	fre = l + 1;
        }
    }

    if(r >= l + 2) 
    {
    	if(find(rig.begin(), rig.end(), root -> val) == rig.end())
    	     return rig;
    	else 
    	{
    		res.push_back(root -> val);
    		fre = r + 1;
    	}
    }

    if(l == r + 1)
    {
    	auto iter_1 = find(rig.begin(), rig.end(), root -> val);
    	auto iter_2 = find(lef.begin(), lef.end(), root -> val);
        
        if(iter_1 == rig.end() && iter_2 == lef.end())
        {	
        	if(r == 0) 
        	{
        	   res.push_back(root -> val);
        	}
        	fre = r;
        	res.insert(res.end(), lef.begin(), lef.end());
        	return res;
        }

        if(iter_2 != lef.end())
        {
        	res.push_back(root -> val);
        	fre = l + 1;
        	return res;
        }

        if(iter_1 != rig.end())
        {
        	res.insert(res.end(), lef.begin(), lef.end());
        	res.insert(res.end(), rig.begin(), rig.end());
        	fre = l;
        	return res;
        }
    }

    if(r == l + 1 )
    {
    	auto iter_1 = find(rig.begin(), rig.end(), root -> val);
    	auto iter_2 = find(lef.begin(), lef.end(), root -> val);

        if(iter_1 == rig.end() && iter_2 == lef.end())
        {
        	if(l == 0) 
        	{
        	   res.push_back(root -> val);
        	}
        	fre = r;
        	res.insert(res.end(), rig.begin(), rig.end());
        	return res;
        }

        if(iter_2 != rig.end())
        {
        	res.push_back(root -> val);
        	fre = r + 1;
        	return res;
        }

        if(iter_1 != lef.end())
        {
        	res.insert(res.end(), lef.begin(), lef.end());
        	res.insert(res.end(), rig.begin(), rig.end());
        	fre = r;
        	return res;
        }
    }

    if(l == r)
    {
    	auto iter_1 = find(rig.begin(), rig.end(), root -> val);
    	auto iter_2 = find(lef.begin(), lef.end(), root -> val);

    	if(iter_1 == rig.end() && iter_2 == lef.end())
    	{
    		res.insert(res.end(), rig.begin(), rig.end());
    		res.insert(res.end(), lef.begin(), lef.end());
    		fre = l;
    		if(l == 1)
    		{
    			res.push_back(root -> val);
    		}
    		return res;
    	}

    	if((iter_1 != rig.end() && iter_2 == lef.end()) || (iter_2 != lef.end() && iter_1 == rig.end()))
    	{
            res.push_back(root -> val);
            fre = l + 1;
            return res;
    	}

    	if(iter_1 != rig.end() && iter_2 != lef.end())
    	{
    		res.push_back(root -> val);
    		fre = l + 2;
    		return res;
    	}
    }


    return res;
   
}

TreeNode* build_tree()
{
	TreeNode* root = new TreeNode(1);
	root -> right = new TreeNode(2);
	return root;
}

void inorder(TreeNode* root) 
{
	if(root != NULL)
	{
		inorder(root -> left);
		cout << (root -> val) << endl;
		inorder(root -> right);
	}
}

int main()
{
	TreeNode* root = build_tree();
	int fre = 0;
	vector<int> res = findM(root, fre);

	for(auto i = 0; i != res.size(); ++i)
		cout << "res[i] : " << res[i] << endl;
	return 0;
}