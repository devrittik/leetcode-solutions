class Solution {
public:
    vector<int> ans;
    vector<vector<int>> finalAns;

    void csHelper(vector<int>& candidates, int& n, int& target, int& index){

        // Base Case
        if(target < 0){
            return;
        }else if(target == 0){
            finalAns.emplace_back(ans);
            return;
        }

        for(int i = index; i < n; i++){
            ans.emplace_back(candidates[i]);
            target -= candidates[i];
            csHelper(candidates, n, target, i);
            target += candidates[i];
            ans.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index = 0, n = candidates.size();
        csHelper(candidates, n, target, index);
        return finalAns;
    }
};