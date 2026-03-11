class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int missing=0;

        for(int I=0; I<n; I++){
            missing=missing^I^nums[I];
        }

        missing=missing^n;

        return missing;
    }
};