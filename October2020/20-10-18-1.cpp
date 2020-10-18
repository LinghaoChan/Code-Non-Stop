/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s!=nullptr && t!=nullptr){
                return (s->val == t->val && isSame(s, t))||(isSubtree(s->left, t)||isSubtree(s->right, t));
        }else{
            return false;
        }
    }
    bool isSame(TreeNode* a, TreeNode*b){
        if(a!=nullptr && b!=nullptr){
            return (a->val == b->val) && isSame(a->left, b->left) && isSame(a->right, b->right);
        }else if(a==nullptr && b==nullptr){
            return true;
        }else{
            return false;
        }
    }
};