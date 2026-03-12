class Solution {
public:
    void mpFounder(vector<int>& prices, int& i, int& minPrice, int& maxProfit) {
        // Base Case
        if (i >= prices.size())
            return;

        // One Case
        if (prices[i] < minPrice)
            minPrice = prices[i];
        if ((prices[i] - minPrice) > maxProfit)
            maxProfit = (prices[i] - minPrice);

        // RE
        mpFounder(prices, ++i, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0, i = 0;
        // RE
        //  mpFounder(prices, i, minPrice, maxProfit);

        // Iterative
        for (; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            if ((prices[i] - minPrice) > maxProfit)
                maxProfit = (prices[i] - minPrice);
        }

        return maxProfit;
    }
};