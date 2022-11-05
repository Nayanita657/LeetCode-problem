https://bit.ly/3r8mG5b
*************************************************MEMOIZATION*********************************************************



int helper(int ind, int target, vector<int>& num, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        if(target == 0)
        {
            if(num[ind] == 0)
                return 2;
            else
                return 1;
        }
        else
        {
            if(num[ind] == target)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        if(dp[ind][target] != -1)
            return dp[ind][target];
        int non_take = helper(ind - 1, target, num, dp);
        int take = 0;
        if(target >= num[ind])
            take = helper(ind - 1, target - num[ind], num, dp);
        dp[ind][target] = (non_take + take) % MOD;
        return dp[ind][target];
    }
}
int findWays(vector<int> &num, int tar)
{    
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return helper(n - 1, tar, num, dp);
}
int countPartitions(int n, int d, vector<int> &arr) 
{
    int total_sum = 0;
    for(int i = 0; i < arr.size(); i++)
        total_sum+=arr[i];
    if((total_sum - d) < 0 || (total_sum - d) % 2)
        return 0;
    int target = (total_sum - d) / 2;
    return findWays(arr, target);
}

TC = 0(N * TARGET)
SC = 0(N * TARGET) + 0(N)
  
*********************************************************TABULATION****************************************************************


int helper(int n, int target, vector<int>& num)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    //base case
    //filling data for ind = 0
    for(int tar = 0; tar <= target; tar++)
    {
        if(tar == 0)
        {
            if(num[0] == tar)
                dp[0][tar] = 2;
            else
                dp[0][tar] = 1;
        }
        else
        {
            if(num[0] == tar)
                dp[0][num[0]] = 1;
            
        }
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            int non_take = dp[i - 1][j];
            int take = 0;
            if(j >= num[i])
                take = dp[i - 1][j - num[i]];
            dp[i][j] = (non_take + take) % MOD;
        }
    }
    return dp[n - 1][target];
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return helper(n, tar, num);
    
}
int countPartitions(int n, int d, vector<int> &arr) 
{
    int total_sum = 0;
    for(int i = 0; i < arr.size(); i++)
        total_sum+=arr[i];
    if((total_sum - d) < 0 || (total_sum - d) % 2)
        return 0;
    int target = (total_sum - d) / 2;
    return findWays(arr, target);
}

TC = O(N * TARGET)
SC = O(N * TARGET)
