//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//time : o(n) time and o(1) space

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, sell = -1, ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
                continue;
            }
            sell = prices[i];
            ans = max(ans, sell - buy);
        }
        return ans;
    }
};