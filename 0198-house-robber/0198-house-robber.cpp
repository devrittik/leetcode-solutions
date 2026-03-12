class Solution {
public:
    int robMax(vector<int>& nums, int i, vector<int>& dp){
        
        //Base Case
        if(i>=nums.size()) return 0;

        // 1 Case
        if(dp[i] != -1) return dp[i];
        // --Inclusion
        int robAmt1 = nums[i] + robMax(nums, i+2, dp);
        // --Exclusion
        int robAmt2 = robMax(nums, i+1, dp);

        //RE
        return dp[i] = max(robAmt1, robAmt2);
        
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robMax(nums, 0, dp);
    }
};