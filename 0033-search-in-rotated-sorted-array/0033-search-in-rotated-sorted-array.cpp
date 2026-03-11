class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        int mid=e/2;

        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            if(nums[s]>nums[mid]){
                //Right Half
                if(nums[mid]<target && target<=nums[e]){
                   s=mid+1; 
                }else{
                    e=mid-1;
                }
            }else{
                //Left Half
                if(nums[mid]<target || target<nums[s]){
                   s=mid+1; 
                }else{
                    e=mid-1;
                }
            }

            mid = s+(e-s)/2;
        }

        return -1;
    }
};