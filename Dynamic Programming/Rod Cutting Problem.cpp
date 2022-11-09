https://bit.ly/3H10kYJ

**********************************************RECURSION********************************************

int helper_rec(int ind, int target, vector<int>& price)
{
    if(ind == 0)
    {
        int len = ind + 1;
        return (int)(target / len) * price[0];
    }
    
    int non_take = helper_rec(ind - 1, target, price);
    int take = INT_MIN;
    int len = ind + 1;
    if(len <= target)
        take = price[ind] + helper_rec(ind, target - len, price);
    return max(non_take, take);
}
int cutRod(vector<int> &price, int n)
{
    int size = price.size();
	  return helper_rec(size - 1, n, price);
}

TC = >>O(2^N)
SC = O(WEIGHT)

***********************************************MEMOIZATION***********************************************

int helper_memo(int ind, int target, vector<int>& price, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        int len = ind + 1;
        return target * price[0];
    }
    
    if(dp[ind][target] != -1)
        return dp[ind][target];
    
    int non_take = 0 + helper_memo(ind - 1, target, price, dp);
    int take = INT_MIN;
    int len = ind + 1;
    if(len <= target)
        take = price[ind] + helper_memo(ind, target - len, price, dp);
    dp[ind][target] = max(non_take, take);
    return dp[ind][target];
}
int cutRod(vector<int> &price, int n)
{
    int size = price.size();
    vector<vector<int>> dp(size , vector<int>(n + 1, -1));
    return helper_memo(size - 1, n, price, dp);
}

TC = O(N * WEIGHT)
SC = O(N * WEIGHT) + O(WEIGHT)

*****************************************TABULATION******************************************

int helper_tabu(int n, int target, vector<int>& price)
{
    vector<vector<int>> dp(n, vector<int> (target + 1, 0));
    for(int tar = 0; tar <= target; tar++)
    {
        dp[0][tar] = tar * price[0];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            int non_take = 0 + dp[i - 1][j];
            int take = INT_MIN;
            int len = i + 1;
            if(len <= j)
                take = price[i] + dp[i][j - len];
            dp[i][j] = max(non_take, take);
        }
    }
    return dp[n - 1][target];
}
int cutRod(vector<int> &price, int n)
{
    int size = price.size();
    return helper_tabu(size, n, price);
}

TC = O(N * WEIGHT)
SC = O(N * WEIGHT)
