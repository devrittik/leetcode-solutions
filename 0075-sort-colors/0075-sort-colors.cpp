class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0, end=(int)(nums.size()-1);
        while(start<end){
            if(nums[start]<1){
                //nums[start]=0
                start++;
            }else if(nums[start]==1){
                //nums[start]=1
                if(nums[start]==nums[end]){
                    //nums[start]=1 & nums[end]=1
                    int i=start+1;
                    bool flag=1;
                    while(i<end){
                        if(nums[end] != nums[i]){
                            swap(nums[end], nums[i]);
                            flag=0;
                            break;
                        }
                        i++;
                    }
                    if(flag){
                        break;
                    }
                }else{
                    //nums[start]=1 & nums[end]=0
                    swap(nums[start],nums[end]);
                }
            }else{
                //nums[start]=2
                if(nums[start] != nums[end]){
                    swap(nums[start],nums[end]);
                }
            }
    
            if(nums[end]>1){
                //nums[end]=2
                end--;
            }
        }
    }
};