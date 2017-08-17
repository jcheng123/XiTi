#include <iostream>

using namespace std;

int pSum(TreeNode* root, int sum) 
{
     if(!root) return 0;
     int num = 0;
     int s = 0, t = 0;

     if(root -> val == sum) num++;
     s = pSum(root -> left, sum - root -> val);
     t = pSum(root -> right, sum - root -> val);
     
     num += (s + t);
     return num;
}

int pathSum(TreeNode* root, int sum) 
{
	if(root)
	{
		int l = pathSum(root -> left, sum);
		l += pSum(root, sum);
		l += pathSum(root -> right, sum);
		return l;
    }
    else return 0;
}



