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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> vec;
        getsum(root, vec);
        map<int, int> m;
        int max = 0;
        // for(int i = 0; i < vec.size(); i++){
        //     cout<<vec[i]<<' ';
        // }
        for(auto item1 : vec){
            m[item1]++;
            if(m[item1] > max){
                max = m[item1];
            }
        }
        vector<int> v;
        for(auto mm : m){
            if(mm.second==max){
                v.emplace_back(mm.first);
            }
        }
        return v;
    }
    int getsum(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            int left = getsum(root->left, vec);
            int right = getsum(root->right, vec);
            vec.emplace_back(left + right + root->val);
            return (left + right + root->val);
        }else{
            return 0;
        }
    }
};