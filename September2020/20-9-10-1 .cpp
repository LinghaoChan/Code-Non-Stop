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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> temp=levelOrder(root);
        int i, j;
        vector<double> final_vec;
        for(i=0;i<temp.size();i++){
            vector<int> t = temp[i];
            double sum = 0;
            for(j=0;j<t.size();j++){
                sum += t[j];
            }
            final_vec.push_back(sum / t.size());
        }
        return final_vec;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> final_vec;
        if(root == NULL) return final_vec;
        vector<TreeNode*> queue1;
        vector<TreeNode*> queue2;
        queue1.push_back(root);
        vector<int> a = {root->val};
        final_vec.push_back(a);
        int i = 0;
        while(!queue1.empty()){
            for(i=0;i<queue1.size();i++){
                if(queue1[i]->left!=NULL)
                queue2.push_back(queue1[i]->left);
                if(queue1[i]->right!=NULL)
                queue2.push_back(queue1[i]->right);
            }
            queue1 = queue2;
            queue2 = {};
            
            vector<int> tmp;
            for(i=0;i<queue1.size();i++){
                tmp.push_back(queue1[i]->val);
            }
            if(!tmp.empty())
            final_vec.push_back(tmp);
        }
        return final_vec;

    }
};