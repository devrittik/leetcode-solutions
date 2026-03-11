class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int result=0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for(int i = 0; i<nums.size()-2; i++){
            if(numSet.count(nums[i]+diff) && numSet.count(nums[i]+2*diff)){
                result++;
            }
        }

        return result;
    }
};