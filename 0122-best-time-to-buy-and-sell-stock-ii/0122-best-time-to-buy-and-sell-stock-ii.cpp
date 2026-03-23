class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy, sell, profit = 0;
        bool stock_in_hand = 0;

        for(int i = 0; i < n-1; i++){
            if(!stock_in_hand and prices[i] < prices[i+1]){
                buy = prices[i];
                stock_in_hand = 1;
            }
            else if(stock_in_hand and prices[i] > prices[i+1]){
                sell = prices[i];
                profit += sell - buy;
                stock_in_hand = 0;
            }
        }

        if(stock_in_hand){
            sell = prices[n-1];
            profit += sell - buy;
        }
        return profit;
    }
};