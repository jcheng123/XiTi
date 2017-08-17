#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	char value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char v) : value(v), left(NULL), right(NULL) {}
};

TreeNode* build_tree(string& s)
{
	stack<TreeNode*> opera;   // to store operator

	for(const auto& i : s)
	{
		if(isdigit(i))
		{
            TreeNode* leaf = new TreeNode(i);
            opera.push(leaf);
		}
		else
		{
			TreeNode* in_node   = new TreeNode(i);

 			TreeNode* opera_1 = opera.top();
			opera.pop();
			TreeNode* opera_2 = opera.top();
			opera.pop();

			in_node -> left  = opera_1;
			in_node -> right = opera_2;
			opera.push(in_node);
		}
	}

	    TreeNode* root = opera.top();
        return root;
}

void inorder(TreeNode* root)
{
	if(root != NULL)
	{
		inorder(root -> left);
		cout << root -> value << endl;
		inorder(root -> right);
	}
}


int main()
{
	string expr = "1289+13*+";
	TreeNode* root = build_tree(expr);
	inorder(root);
	return 0;
}

