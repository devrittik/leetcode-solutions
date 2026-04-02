class Solution {
public:
    void mergeInplace(vector<int>& arr, int s, int e) {
        int len = (e-s+1);
        int gap = len/2 + len%2;

        while(gap>0){
            int i = s, j = s+gap;
            while(j<=e){
                if(arr[i] > arr[j]){
                    swap(arr[i],arr[j]);
                }
                i++;
                j++;
            }
            gap = gap<=1 ? 0 : (gap/2 + gap%2);
        }
    }

    void mergeSort(vector<int>& arr, int s, int e) {

        // base case
        if (s >= e)
            return;

        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);

        mergeInplace(arr, s, e);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        mergeSort(nums, s, e);
        return nums;
    }
};