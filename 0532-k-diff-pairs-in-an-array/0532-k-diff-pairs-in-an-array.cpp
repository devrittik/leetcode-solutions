class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=1,diff;
        set<pair<int,int>> ans;
        while(j<nums.size()){
            diff=nums[j]-nums[i];
            if(diff==k){
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }else if(diff<k){
                j++;
            }else{
                i++;
            }
            if(i==j){
                j++;
            }
        }

        return ans.size();
    }
};