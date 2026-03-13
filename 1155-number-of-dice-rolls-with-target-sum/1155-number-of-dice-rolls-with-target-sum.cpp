class Solution {
public:
    int nRT(int n, int& k, int target, map<pair<int,int>,int>& dp){
        
        //Base Case
        if(target < 0) return 0;
        if(n==0 && target==0) return 1;
        if((n!=0 && target==0) || (n==0 && target!=0)) return 0;

        //DP
        auto it = dp.find({n,target});
        if(it != dp.end()) return it->second;

        //One Case
        long long ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + nRT(n-1,k,target-i,dp))%1000000007;
        }

        return dp[{n,target}] = ans;

    }
    int numRollsToTarget(int n, int k, int target) {
        map<pair<int,int>,int> dp;
        return nRT(n,k,target,dp);
    }
};