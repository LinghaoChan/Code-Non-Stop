class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 1;
        int sum = 0;
        while(i<prices.size()){
            if(prices[i] > prices[i - 1]){
                sum+=(prices[i] - prices[i - 1]);
            }
            i++;
        }
        return sum;
    }
};