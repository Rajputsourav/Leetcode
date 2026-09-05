class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p = prices[0];
        int max_p = 0;
        for (int i = 0; i < prices.size(); i++) {
            max_p = max(max_p, prices[i]-min_p);
            min_p = min(min_p, prices[i]);
        }
        return max_p;
    }
};