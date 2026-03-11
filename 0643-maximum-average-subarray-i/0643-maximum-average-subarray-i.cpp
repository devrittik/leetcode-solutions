class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double maxSum=0, currSum=0;

        for(int i=0; i<k; i++){
            currSum+=nums[i];
        }
        maxSum=currSum;

        for(int i=k; i<n; i++){
            currSum+=nums[i]-nums[i-k];
            maxSum=max(maxSum,currSum);
        }

        return maxSum/k;
    }
};