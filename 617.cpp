#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* buildTree_1()
{
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(3);
	root -> left -> left = new TreeNode(5);
	root -> right  = new TreeNode(2);
	return root;
}

TreeNode* buildTree_2()
{
	TreeNode* root = new TreeNode(2);
	root -> left  = new TreeNode(1);
	root -> left -> right = new TreeNode(4);
	root -> right  = new TreeNode(3);
	root -> right -> right = new TreeNode(5);
	return root;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
	    if(t1 == NULL && t2 == NULL) return NULL;
        TreeNode* root = new TreeNode(0);
        if(t1 == NULL) 
        {
            root -> val = t2 -> val;
        }
        else if(t2 == NULL)
        {
            root -> val = t1 -> val;
        }
        else  root -> val = t1 -> val + t2 -> val;
        
        if(root != NULL) root -> left = mergeTrees(t1 -> left, t2 -> left);
        if(root != NULL) root -> right = mergeTrees(t1 -> right, t2 -> right);
        
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
	TreeNode* t1 = buildTree_1();
	TreeNode* t2 = buildTree_1();

	TreeNode* root = mergeTrees(t1, t2);
	inorder(root);

	return 0;


}