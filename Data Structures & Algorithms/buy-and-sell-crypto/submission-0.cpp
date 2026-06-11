class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int profit = 0;

        while(right < prices.size()){
            if(prices[left] < prices[right]){
                int currProfit = prices[right] - prices[left];
                profit = max(profit, currProfit);
            }else{
                left = right;
            }
            right ++;
        } 
        return profit;

    }
};
