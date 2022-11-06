https://bit.ly/33Kd8o2

*******************************************************RECURSION**********************************************

int helper_rec(int ind, int target, int* arr)
{
    if(ind == 0)
    {
        if((target % arr[0]) == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int non_take = helper_rec(ind - 1, target, arr);
        int take = 0;
        if(target >= arr[ind])
            take = helper_rec(ind, target - arr[ind], arr);
        return take + non_take;
    }
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return helper_rec(n - 1, value, denominations);
}
TC = >>O(2 ^ N)
SC = O(TARGET)
  
***************************************************MEMOIZATION*********************************************************

long helper_memo(int ind, int target, int* arr, vector<vector<long>>& dp)
{
    if(ind == 0)
    {
        if((target % arr[0]) == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(dp[ind][target] != -1)
            return dp[ind][target];
        long non_take = helper_memo(ind - 1, target, arr, dp);
        long take = 0;
        if(target >= arr[ind])
            take = helper_memo(ind, target - arr[ind], arr, dp);
        dp[ind][target] = take + non_take;
        return dp[ind][target];
    }
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return helper_memo(n - 1, value, denominations, dp);
}
TC = O(N * TARGET)
SC = O(N * TARGET) + O(TARGET)
  
*******************************************************************TABULATION*************************************************
long helper_tabu(int n, int target, int* arr)
{
    vector<vector<long>> dp(n, vector<long>(target + 1, 0));
    //base case
    for(int i = 0; i <= target; i++)
    {
        if((i % arr[0]) == 0)
            dp[0][i] = 1;
    }
   for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                long non_take = dp[i - 1][j];
                long take = 0;
                if(j >= arr[i])
                    take = dp[i][j - arr[i]];
                dp[i][j] = take + non_take;
            }
        }
    return dp[n - 1][target];
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return helper_tabu(n, value, denominations);
}
TC = O(N * TARGET)
SC = O(N * TARGET)
