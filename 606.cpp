#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* build_tree()
{
	TreeNode* head = new TreeNode(1);
	head -> left = new TreeNode(2);
	head -> right = new TreeNode(3);
	head -> left -> right = new TreeNode(4);
	return head;
}

string tree2str(TreeNode* t) 
{
    string res = "";
    if(t == NULL) return res;
    
    if(t -> left == NULL && t -> right == NULL) res += to_string(t -> val);
    if(t -> right != NULL)
    res += to_string(t -> val) + "(" + tree2str(t -> left) + ")" + "(" +
            tree2str(t -> right) + ")";
    if(t -> right == NULL && t -> left != NULL)
    	res += to_string(t -> val) + "(" + tree2str(t -> left) + ")"; 
    return res;
        
}

int main()
{
	cout << tree2str(build_tree()) << endl;
	return 0;
}