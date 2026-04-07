class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int temp = 0;
        int consec = 0;
        int left = 0;
        int right = 1;
        while (right < nums.size()){
            if (nums[left] == nums[right]){
                left++;
                right++; 
            }
            else if(nums[right] == (nums[left] + 1)){
                temp++;
                left++;
                right++;
            }
            else{
                if(temp > consec){
                    consec = temp;
                }
                temp = 0;
                left = right; 
                right = left + 1;
            }
        }
        if (temp > consec){
            consec = temp;
        }
        return consec + 1;
    }
};
