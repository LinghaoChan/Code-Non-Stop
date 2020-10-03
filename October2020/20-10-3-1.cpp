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
    vector<int> findMode(TreeNode* root) {
        vector<int> vec, finalvec;
        if(root==NULL)return finalvec;
        midthrough(root, vec);
        int i;
        int count = 0, maxcount = 0;
        int tmp = vec[0];
        for(i=0;i<vec.size();i++){
            if(tmp!=vec[i]){
                // if(count==maxcount) finalvec.push_back(tmp);
                // else if(count>maxcount){
                //     finalvec.clear();
                //     finalvec.push_back(tmp);
                //     maxcount=count;
                // }
                tmp = vec[i];
                count = 1;
                if(count==maxcount) finalvec.push_back(tmp);
                else if(count>maxcount){
                    finalvec.clear();
                    finalvec.push_back(tmp);
                    maxcount=count;
                }
            }else{
                count++;
                if(count==maxcount) finalvec.push_back(tmp);
                else if(count>maxcount){
                    finalvec.clear();
                    finalvec.push_back(tmp);
                    maxcount=count;
                }
            }
            // for(int j=0;j<finalvec.size();j++){
            //     cout<<finalvec[j]<<' ';
            // }
            // cout<<endl;
        }
        return finalvec;
    }

    void midthrough(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            midthrough(root->left,vec);
            vec.push_back(root->val);
            midthrough(root->right,vec);
        }
    }
};