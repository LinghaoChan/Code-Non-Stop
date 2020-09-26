class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pre=0, aft = numbers.size()-1;
        while(pre!=aft){
            if(numbers[pre] + numbers[aft] == target) return vector<int>{pre+1, aft+1};
            else if(numbers[pre] + numbers[aft] < target) pre++;
            else aft--;
            
        }
        return vector<int>{pre+1, aft+1};
    }
};