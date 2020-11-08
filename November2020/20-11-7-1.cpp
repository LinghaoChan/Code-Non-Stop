
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return judge(root -> left, root -> right);
    }
    bool judge(TreeNode *l, TreeNode *r)
    {
        if(!l && !r) return true; // 如果既没有左子树也没有右子树，true
        if(!l || !r) return false; // 如果有右没左或者有左没右，false
        if(l -> val != r -> val) return false; // 如果左右都有，但是值不相等，false
        return judge(l -> left, r -> right) && judge(l -> right, r -> left);
    }
};