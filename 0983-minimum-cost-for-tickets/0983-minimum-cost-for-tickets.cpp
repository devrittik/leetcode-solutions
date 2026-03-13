class Solution {
public:
    int mcTkt(vector<int>& days, vector<int>& costs, vector<int>& dp, int i=0){

        //Base Case
        if(i>=days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        //Ek Case
        // -- 1 Day Pass --
        int cost1 = costs[0] + mcTkt(days, costs, dp, i+1);

        // -- 7 Day Pass --
        int expiry = days[i] + 7 - 1;
        int j = upper_bound(days.begin(), days.end(), expiry) - days.begin();
        int cost7 = costs[1] + mcTkt(days, costs, dp, j);
        
        // -- 30 Day Pass --
        expiry = days[i] + 30 - 1;
        j = upper_bound(days.begin(), days.end(), expiry) - days.begin();
        int cost30 = costs[2] + mcTkt(days, costs, dp, j);

        return dp[i] = min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> dp(days.size(), -1);
        return mcTkt(days, costs, dp);

    }
};