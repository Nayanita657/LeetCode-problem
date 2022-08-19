https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*****************************SOLUTION**********************
using sliding window the question is solved

 int maxProfit(vector<int>& prices) 
    {
        int start = 0;
        int end = start + 1;
        int profit = 0;
        while(end < prices.size())
        {
            if(prices[end] > prices[start])
            {
                int curr_profit = prices[end] - prices[start];
                profit = max(profit, curr_profit);
                end++;
            }
            else
            {
                start = end;
                end++;
            }
        
        }
        return profit;
    }

TC = O(N)
SC = O(1)
