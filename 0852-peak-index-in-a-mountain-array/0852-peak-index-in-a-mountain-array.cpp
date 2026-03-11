class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size=arr.size();
        int s=0, e=size-1, m;

        while(s<e){
            m=s+(e-s)/2;
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){
                //peak=m
                return m;
            }else if(arr[m]<arr[m+1]){
                //increasing
                //m=left of peak
                s=m;
            }else{
                //decreasing
                //m=right of peak
                e=m;
            }
        }

        return -1;
    }
};