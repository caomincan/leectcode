class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int max_profit = 0;
        int sum = 0;
        for(int i=1; i< prices.size();i++){
            int diff = prices[i]-prices[i-1];
            sum = max(diff, sum+ diff);
            max_profit = max(sum, max_profit);
        }
        return max_profit;
    }
};