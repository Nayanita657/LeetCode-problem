
https://bit.ly/3r8mG5b
******************************************RECURSION****************************************
int helper(int ind, int target, vector<int>& num)
{
    if(target == 0)
        return 1;
    if(ind == 0)
       return (num[ind] == target);
    else
    {
        int non_take = helper(ind - 1, target, num);
        int take = 0;
        if(num[ind] <= target)
            take = helper(ind - 1, target - num[ind], num);
        return non_take + take;
    }
}
int findWays(vector<int> &num, int tar)
{
    
    int n = num.size();
    return helper(n - 1, tar, num);
}

TC = O(2 ^ N)
SC = O(N)
  
***************************************MEMOIZATION*****************************************
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
        dp[ind][target] = non_take + take;
        return dp[ind][target];
    }
}
int findWays(vector<int> &num, int tar)
{    
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return helper(n - 1, tar, num, dp);
}
TC = O(N * TARGET)
SC = O(N * TARGET) + o(N)
  
*************************************************TABULATION********************************************

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
            dp[i][j] = non_take + take;
        }
    }
    return dp[n - 1][target];
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return helper(n, tar, num);
    
}
TC = O(N * TARGET)
SC = O(N * TARGET)
