class Solution {
public:
    int calPoints(vector<string>& ops) {
        int i;
        int len = ops.size();
        stack<int> st={};
        for(i = 0; i < len ;i++){
            if(ops[i] == "+"){
                int last = st.top();
                st.pop();
                int last2 = st.top();
                st.pop();
                int sum = last + last2;
                st.push(last2);
                st.push(last);
                st.push(last2+last);
            }else if(ops[i] == "D"){
                int last = st.top();
                st.push(last * 2);
            }else if(ops[i] == "C"){
                st.pop();
            }else{
                int x = stoi(ops[i]);
                st.push(x);
            }
            
        }
        int sum = 0;
        int size = st.size();
        for(i=0;i<size;i++){
            int num = st.top();
            st.pop();
            sum += num;
        }
        return sum;
    }
};