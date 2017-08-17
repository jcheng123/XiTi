#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* find(TreeNode* root, int v)
{
	if(root == NULL) return NULL;
	if(root -> val == v) return root;
	TreeNode* l = find(root -> left, v);
	if(l != NULL) return l;
	TreeNode* r = find(root -> right, v);
	return r;
}
void search(TreeNode* root)
{
	if(root != NULL)
	{
		cout << root -> val << endl;
		search(root -> left);
		search(root -> right);
	}
}


TreeNode* bTree(vector<int>& preorder, vector<int>& inorder , int pre_s, int pre_e, int in_s, int in_e)
{
	

	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return bTree(preorder, inorder, 0, (int)preorder.size());
}

void inorder_s(TreeNode* root)
{
	if(root != NULL)
	{
		inorder_s(root -> left);
		cout << root -> val << endl;
		inorder_s(root -> right);
	}
}

int main()
{
	vector<int> preorder = {1,2,3,5,4,7,6,8,9};
	vector<int> inorder  = {3,5,2,4,1,6,7,9,8};
	TreeNode* head = buildTree(preorder, inorder);
	inorder_s(head);
	return 0;
}