class Solution {
public:
    int msaHelper(vector<int>& nums, int start, int end){

        if(start == end) return nums[start];

        int maxLSum = INT_MIN, maxRSum = INT_MIN;

        int mid = start + ((end-start) >> 1);
        
        int leftSum = msaHelper(nums, start, mid);
        int rightSum = msaHelper(nums, mid+1, end);

        int slideSum = 0;
        for(int i = mid; i >= start; i--){
            slideSum += nums[i];
            if(slideSum > maxLSum) maxLSum = slideSum;
        }

        slideSum = 0;
        for(int i = mid+1; i <= end; i++){
            slideSum += nums[i];
            if(slideSum > maxRSum) maxRSum = slideSum;
        }
        
        int crossSum = maxLSum + maxRSum;

        return max(crossSum, max(leftSum, rightSum));
    }

    int maxSubArray(vector<int>& nums) {
        return msaHelper(nums, 0, nums.size()-1);
    }
};