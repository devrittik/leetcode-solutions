class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int need = mean*(m+n);
        vector<int> res={};
        for(int I=0; I<m; I++){
            need-=rolls[I];
        }
        
        if(need>=n && need<=6*n){
            int reg=need/n;
            int rem=need%n;
            res.assign(n, reg);
            for(int I=0; I<n; I++){
                if(rem<=6-res[I]){
                    res[I]+=rem;
                    break;
                }else{
                    rem-=(6-res[I]);
                    res[I]=6;
                }
            }
        }
        return res;
    }
};