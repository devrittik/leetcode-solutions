class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prev = {1};
        for(int row=1; row<=numRows; row++){
            vector<int> curr = {};
            for(int i = 0; i<row; i++){
                if(i==0 || i==row-1){
                    curr.emplace_back(1);
                }else{
                    curr.emplace_back(prev[i]+prev[i-1]);
                }
            }
            result.emplace_back(curr);
            prev.swap(curr);
            vector<int>().swap(curr);
        }
        return result;
    }
};