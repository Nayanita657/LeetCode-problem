https://bit.ly/3HJTeIl

**********************************************RECURSION****************************************

int helper_rec(int ind, int target, vector<int>& num)
{
    if(ind == 0)
    {
        if((target % num[0]) == 0)
            return (target / num[0]);
        else
            return 1e9;
    }
    else
    {
        int non_take = 0 + helper_rec(ind - 1, target, num);
        int take = INT_MAX;
        if(target >= num[ind])
            take = 1 + helper_rec(ind, target - num[ind], num);
        return min(non_take, take);
    }
}
int minimumElements(vector<int> &num, int x)
{

    int n = num.size();
    int ans = helper_rec(n - 1, x, num);
    if(ans >= 1e9)
        return -1;
    else
        return ans;
}
TC =
SC =
  
**************************************************MEMOIZTION*******************************************************

int helper_memo(int ind, int target, vector<int>& num, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        if((target % num[0]) == 0)
            return (target / num[0]);
        else
            return 1e9;
    }
    else
    {
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int non_take = 0 + helper_memo(ind - 1, target, num, dp);
        int take = INT_MAX;
        if(target >= num[ind])
            take = 1 + helper_memo(ind, target - num[ind], num, dp);
        dp[ind][target] = min(non_take, take);
        return dp[ind][target];
    }
}
int minimumElements(vector<int> &num, int x)
{

    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = helper_memo(n - 1, x, num, dp);
    if(ans >= 1e9)
        return -1;
    else
        return ans;
}
TC =
SC =
  
**************************************************TABULATION****************************************************

int helper_tabu(int n, int target, vector<int>& num)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    //base case
    for(int i = 0; i <= target; i++)
    {
        if((i % num[0]) == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
             int non_take = 0 + dp[i - 1][j];
             int take = INT_MAX;
             if(j >= num[i])
                take = 1 + dp[i][j - num[i]];
             dp[i][j] = min(non_take, take);
        }
    }
    return dp[n - 1][target];
}
int minimumElements(vector<int> &num, int x)
{

    int n = num.size();
    int ans = helper_tabu(n, x, num);
    if(ans >= 1e9)
        return -1;
    else
        return ans;
}
TC =
SC = 
