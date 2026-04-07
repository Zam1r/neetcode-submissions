class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int currentSize = nums.size(); 
        for(int i = 0; i < currentSize; i++){
            for(int j = i+1; j< currentSize; j++){
                if (nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
