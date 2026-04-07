class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> prefix(sz);
        prefix[0] = nums[0];
        vector<int> suffix(sz);
        suffix[0] = nums[sz - 1];
        for(int i = 1; i< sz; i++){
            prefix[i] = prefix[i - 1] * nums[i];
            suffix[i] = suffix[i - 1] * nums[sz - 1 - i];
        }
        vector<int> res(sz);
        res[0] = suffix[sz - 2];
        res[sz - 1] = prefix[sz - 2];
        for(int i = 1; i < sz - 1; i++){
            res[i] = suffix[sz - 2 - i] * prefix[i - 1];
        }
        return res; 
    }
};
