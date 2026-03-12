class Solution {
public:
    int countSqr(int n, unordered_map<int, int>& dp){

        // Base Case
        if(n == 0) return 1;
        if(n < 0) return 0;

        //Ek Case
        auto it = dp.find(n);
        if(it != dp.end()) return it->second;
        int ans = n+1; // +1 for Edge Case : n = 1
        int end = sqrt(n);
        for(int i=1; i<=end; i++){
            int numPerfectSqrs = 1 + countSqr((n-i*i), dp);
            ans = ans > numPerfectSqrs ? numPerfectSqrs : ans ;
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        unordered_map<int, int> dp;
        return (countSqr(n, dp)-1);
    }
};