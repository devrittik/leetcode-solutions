class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        for(int i=0; i<=rowIndex; i++){
            vector<int> curr = {};
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    curr.emplace_back(1);
                }else{
                    curr.emplace_back(prev[j]+prev[j-1]);
                }
            }
            prev = curr;
        }
        
        return prev;
    }
};