#include <vector>
#include <iostream>
#include <string>

/*
 * 
 */

using namespace std; 

bool hasPathSum(TreeNode* root, int sum) 
{
    if(root == NULL) return false;
    if(root -> left == NULL && root -> right == NULL) return (root -> val == sum);
    bool left  = hasPathSum(root -> left, sum - root -> val);
    bool right = hasPathSum(root -> right, sum - root -> val);
    return (left || right);
} 

