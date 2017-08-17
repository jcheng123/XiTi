#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* deleteNode(TreeNode* root, int key)
{
  TreeNode* ptr = root;
  TreeNode* pptr = root;
  if(ptr -> val == key) return root;

  while(ptr != NULL)
  {
    if(ptr -> val == key)
    {
      TreeNode* r = ptr;
      TreeNode* pr =
      r = r -> right;
      if(r == NULL)
      {
        if(pptr -> left == ptr) pptr -> left = ptr -> left;
        if(pptr -> right == ptr) pptr -> right = ptr -> left;
      }
      else
      {
        while(r -> left != NULL)
        {
          r = r -> left;
        }
        if(pptr -> left == ptr)
        {
          pptr -> left = r;
          r -> left = ptr -> left;
          r -> right = ptr -> right;
      }
    }
    else if(ptr -> val > key) { pptr = ptr; ptr = ptr -> left; }
         else { pptr = ptr; ptr = ptr -> right;}
  }
  return NULL;
}
