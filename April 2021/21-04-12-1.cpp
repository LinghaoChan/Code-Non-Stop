class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> vec(n, 0);
        int flag = 0;
        vector<int> vv(n, 0);
        for(int i = 0; i < n; i++){
            if(leftChild[i]!=-1)
            vv[leftChild[i]]++;
            if(rightChild[i]!=-1)
            vv[rightChild[i]]++;
        }
        int count = 0;
        int root = 0;
        for(int i = 0; i < n; i++){
            if(vv[i]==0){
                count++;
                root = i;
                if(count > 1)return false;
            }
            if(vv[i] >1)return false;
        }
        if(count!=1)return false;

        order(root, leftChild, rightChild, flag, vec);
        if(flag == 1){
            return false;
        }
        for(int i = 0; i < vec.size(); i++){
            if(vec[i]==0){
                return false;
            }
        }
        return true;
    }
    void order(int item, vector<int>& leftChild, vector<int>& rightChild, int& flag, vector<int>& vec){
        if(item!=-1){
            int left = leftChild[item];
            int right = rightChild[item];
            // cout<<item<<endl;
            vec[item] = 1;
            if(left!=-1){
                if(vec[left] == 1){
                    flag = 1;
                    return;
                }
            }
            if(right!=-1){
                if(vec[right] == 1){
                    flag = 1;
                    return;
                }
            }
            order(left, leftChild, rightChild, flag, vec);
            order(right, leftChild, rightChild, flag, vec);
        }
    }
};