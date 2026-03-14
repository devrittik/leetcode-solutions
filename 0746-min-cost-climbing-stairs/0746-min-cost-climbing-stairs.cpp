class Solution {
public:
    int mcSt(vector<int>& cost, vector<int>& dp, int i){
        //Base
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        //One Case
        int curr = (i == cost.size()) ? 0 : cost[i];
        int costI = curr + mcSt(cost, dp, i-2);
        int costE = curr + mcSt(cost, dp, i-1);

        return dp[i] = min(costI, costE);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i = cost.size();
        vector<int> dp(i+1, -1);
        return mcSt(cost, dp, i);
    }
};