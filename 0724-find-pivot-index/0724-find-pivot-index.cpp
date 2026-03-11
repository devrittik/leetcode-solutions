class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size=nums.size();

        int totalSum=0;
        for(int num : nums){
            totalSum+=num;
        }

        int leftSum=0;
        for(int i=0; i<size; i++){
            if(leftSum==(totalSum-nums[i]-leftSum)){
                return i;
            }
            leftSum+=nums[i];
        }

        return -1;
    }
};