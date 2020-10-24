class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        vector<int> res;
        unordered_map<int, int>map;
        int t1, t2;
        for (auto val : nums)
        {
            map[val]++;
        }
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (map[i] == 0)
                t2 = i;
            if (map[i] == 2)
                t1 = i;
        }
        res.push_back(t1);
        res.push_back(t2);
        return res;
    }
};