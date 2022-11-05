https://bit.ly/3KHpP3v

****************************************RECURSION***********************************************

int helper_recursion(vector<int>& weight, vector<int>& value, int ind, int maxWeight)
{
    //base case
    if(ind == 0)
    {
        if(weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    else
    {
        int non_take = 0 + helper_recursion(weight, value, ind - 1, maxWeight);
        int take = INT_MIN;
        if(weight[ind] <= maxWeight)
            take = value[ind] + helper_recursion(weight, value, ind - 1, maxWeight - weight[ind]);
        return max(non_take, take);
    }
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	  return helper_recursion(weight, value, n - 1, maxWeight);
   
}

TC = O(2^N)
SC = O(N)
  
************************************************MEMOIZATION************************************************

int helper_memo(vector<int>& weight, vector<int>& value, int ind, int maxWeight, vector<vector<int>>& dp)
{
    //base case
    if(ind == 0)
    {
        if(weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    else
    {
        if(dp[ind][maxWeight] != -1)
            return dp[ind][maxWeight];
        
        int non_take = 0 + helper_memo(weight, value, ind - 1, maxWeight, dp);
        int take = INT_MIN;
        if(weight[ind] <= maxWeight)
            take = value[ind] + helper_memo(weight, value, ind - 1, maxWeight - weight[ind], dp);
        dp[ind][maxWeight] = max(non_take, take);
        return dp[ind][maxWeight];
    }
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return helper_memo(weight, value, n - 1, maxWeight, dp);
   
}
TC = O(N * maxWeight)
SC = O(N * maxWeight) + O(N)

****************************************************TABULATION******************************************

int helper_tabu(vector<int>& weight, vector<int>& value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    //base case
    //fill the columns for index 0
    for(int i = 0; i <= maxWeight; i++)
    {
        if(weight[0] <= i)
            dp[0][i] = value[0];
    }
    for(int i = 1; i < n; i++)
    {
         for(int j = 0; j <= maxWeight; j++)
         {
               int non_take = 0 + dp[i - 1][j];
               int take = INT_MIN;
               if(weight[i] <= j)
                    take = value[i] + dp[i - 1][j - weight[i]];
                 dp[i][j] = max(non_take, take);
            }
        }
   
    return dp[n - 1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return helper_tabu(weight, value, n, maxWeight);
}
TC = O(N * maxWeight)
SC = O(N * maxWeight)
