https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

***********************************SOLUTION*******************************************


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    //vector<vector<int>dp;
    int helper(int W, int wt[], int val[], int n, vector<vector<int>>& dp)
    {
        if(n == 0 || W == 0)
            return 0;
        else
        {
            if(dp[n][W] != -1)
                return dp[n][W];
            else
            {
                if(wt[n - 1] <= W)
                {
                    int val1 = val[n - 1] + helper(W - wt[n - 1], wt, val, n - 1, dp);
                    int val2 = helper(W, wt, val, n - 1, dp);
                    dp[n][W] = max(val1, val2);
                    return dp[n][W];
                }
                
                else
                    dp[n][W] = helper(W, wt, val, n - 1, dp);
                    return dp[n][W];
            }
            
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp;
        for(int i = 0; i < n + 1; i++)
        {
            vector<int> inner_dp;
            for(int j = 0; j < W + 1; j++)
            {
                inner_dp.push_back(-1);
            }
            dp.push_back(inner_dp);
        }
        
        return helper(W, wt, val, n, dp);
        
    
    }
};
