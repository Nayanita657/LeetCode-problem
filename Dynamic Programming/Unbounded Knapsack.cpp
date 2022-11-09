https://bit.ly/3IvPdXS

*******************************************RECURSION*********************************************

int helper_rec(int ind, int W, vector<int>& profit, vector<int>& weight)
{
    if(ind == 0)
    {
        if(W >= weight[0])
        {
            int temp = W / weight[0];
            return (temp * profit[0]);
        }
        else
            return 0;
    }
    else
    {
        int non_take = 0 + helper_rec(ind - 1, W, profit, weight);
        int take = INT_MIN;
        if(W >= weight[ind])
            take = profit[ind] + helper_rec(ind, W - weight[ind], profit, weight);
        return max(non_take, take);
    }
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return helper_rec(n - 1, w, profit, weight);
}

TC = >>O(N * WEIGHT)
SC = O(WEIGHT) + O(N * WEIGHT)
  
********************************************MEMOIZATION**************************************************

int helper_memo(int ind, int W, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        if(W >= weight[0])
        {
            int temp = W / weight[0];
            return (temp * profit[0]);
        }
        else
            return 0;
    }
    
    else
    {
        if(dp[ind][W] != -1)
        {
            return dp[ind][W];
        }
        int non_take = 0 + helper_memo(ind - 1, W, profit, weight, dp);
        int take = INT_MIN;
        if(W >= weight[ind])
            take = profit[ind] + helper_memo(ind, W - weight[ind], profit, weight, dp);
        dp[ind][W] = max(non_take, take);
        
        return dp[ind][W];
    }
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return helper_memo(n - 1, w, profit, weight, dp);
}
TC = O(N * WEIGHT)
SC = O(WEIGHT) + O(N * WEIGHT)

****************************************TABULATION**********************************************

int helper_tabu(int n, int W, vector<int>& profit, vector<int>& weight)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    //base case
    for(int i = 0; i <= W; i++)
    {
        if(i >= weight[0])
        {
            int temp = i / weight[0];
            dp[0][i] = temp * profit[0];
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            int non_take = dp[i - 1][j];
            int take = INT_MIN;
            if(j >= weight[i])
                take = profit[i] + dp[i][j - weight[i]];
            dp[i][j] = max(non_take, take);
        }
    }
    return dp[n - 1][W];      
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return helper_tabu(n, w, profit, weight);
}

TC = O(N * WEIGHT)
SC = O(N * WEIGHT)
  
