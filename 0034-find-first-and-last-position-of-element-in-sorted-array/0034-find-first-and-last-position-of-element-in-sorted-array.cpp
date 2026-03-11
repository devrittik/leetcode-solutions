class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size=nums.size();
        int s=0, e=size-1;
        vector<int> ans={-1,-1};
        int fo, lo;
        int m;
        while(s<=e){
            m = s + (e-s)/2;
            if(nums[m]==target){
                //m=target
                fo=m;
                lo=m;
                while(fo>0 && nums[fo-1]==target){
                    fo--;
                }
                while(lo<=size-2 && nums[lo+1]==target){
                    lo++;
                }
                ans={fo,lo};
                return ans;
            }else if(nums[m]<target){
                //target>m
                // if(nums[e]>target){
                //     e--;
                // }else if(nums[e]==target){
                //     lo=e;
                //     fo=e;
                //     while(fo>0 && nums[fo-1]==target){
                //         fo--;
                //     }
                //     ans={fo,lo};
                //     return ans;
                // }
                s=m+1;
            }else{
                //target<m
                // if(nums[s]<target){
                //     s++;
                // }else if(nums[s]==target){
                //     lo=s;
                //     fo=s;
                //     while(lo<=size-2 && nums[lo+1]==target){
                //         lo++;
                //     }
                //     ans={fo,lo};
                //     return ans;
                // }
                e=m-1;
            }
        }
        return ans;
    }
};