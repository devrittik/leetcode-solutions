class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        int mid=e/2;

        while(s<=e){
            if(s==e){
                return nums[s];
            }

            if(mid%2==0){
                //mid==even
                if(nums[mid]==nums[mid+1]){
                    //left side
                    s=mid+2;
                }else{
                    //ans or right side
                    e=mid;
                }
            }else{
                //mid==odd
                if(nums[mid]==nums[mid+1]){
                    //right side
                    e=mid-1;
                }else{
                    //left side
                    s=mid+1;
                }
            }

            mid=s+(e-s)/2;
        }

        return -1;
    }
};