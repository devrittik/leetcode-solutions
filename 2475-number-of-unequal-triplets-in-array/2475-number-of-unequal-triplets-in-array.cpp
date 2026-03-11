class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count=0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]!=nums[i]){
                    for(int k = j+1; k<nums.size(); k++){
                        if(nums[k]!=nums[j] && nums[k]!=nums[i]){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};