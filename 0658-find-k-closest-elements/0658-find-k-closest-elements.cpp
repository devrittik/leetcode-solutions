class Solution {
public:

    vector<int> twoPtr(vector<int>& arr, int k, int x){
        int l=0, h=arr.size()-1;

        while(h-l>=k){
            if(x-arr[l]>arr[h]-x){
                l++;
            }else{
                h--;
            }
        }

        return vector<int>(arr.begin()+l, arr.begin()+h+1);
    }

    int lowerBound(vector<int>& arr, int x){
        int start=0, end=arr.size()-1;
        int mid=end/2;
        int ans=end;

        while(start<=end){
            if(arr[mid]>=x){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }

            mid=start+(end-start)/2;
        }

        return ans;
    }

    vector<int> binS(vector<int>& arr, int k, int x){
        int h=lowerBound(arr, x);
        int l=h-1;

        while(k--){
            if(l<0){
                h++;
            }else if(h>=arr.size()){
                l--;
            }else if(arr[h]-x<x-arr[l]){
                h++;
            }else{
                l--;
            }
        }

        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Two Pointer Approach
        // return twoPtr(arr, k, x);
        //Binary Search Method
        return binS(arr, k, x);
    }
};