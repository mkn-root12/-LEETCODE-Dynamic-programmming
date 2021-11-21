 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int pe;
    inline int searchInorder(vector<int> &inorder, int is, int ie, int target)
    {
        for (int i = is; i <= ie; i++)
            if (inorder[i] == target)
                return i;
        return -1;
    }
    TreeNode *getTree(vector<int> &inorder, vector<int> &postorder,
                      int is, int ie)
    {
        if (is > ie)
            return NULL;
        if (is == ie)
            return new TreeNode(postorder[pe--]);
        int idx = searchInorder(inorder, is, ie, postorder[pe]);
        TreeNode *root = new TreeNode(postorder[pe--]);
        root->right = getTree(inorder, postorder, idx + 1, ie);
        root->left = getTree(inorder, postorder, is, idx - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        pe = postorder.size() - 1;
        return getTree(inorder, postorder, 0, inorder.size() - 1);
    }
};
