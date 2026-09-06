class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int min_p=prices[0];
        int n = prices.size();
        for(int i=1;i<n ;i++){
             min_p = min(min_p,prices[i]);
             mp = max(mp, prices[i]-min_p);
        }
        return mp;
    }
};