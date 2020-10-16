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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTWithIndex(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArrayToBSTWithIndex(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode();
        int root_index = (left + right) / 2;
        root->val = nums[root_index];
        root->left = sortedArrayToBSTWithIndex(nums, left, root_index - 1);
        root->right = sortedArrayToBSTWithIndex(nums, root_index + 1, right);
        return root;
    }
};