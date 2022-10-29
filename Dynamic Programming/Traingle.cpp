https://leetcode.com/problems/triangle/description/

*********************************************RECURSION***************************************

int helper(int i, int j, int n, vector<vector<int>>& traingle)
    {
        if(i == n)
            return traingle[i][j];
        else
        {
            
            int down = traingle[i][j] + helper(i + 1, j, n, traingle, dp);
            int diagonal = traingle[i][j] + helper(i + 1, j + 1, n, traingle, dp);
            return min(down, diagonal);
            
        }
    }
int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(triangle);
    }

TC = O(2 ^ N2)
SC = O(N) //LENGTH OF THE ROW

***********************************************MEMOIZATION***************************************
int helper(int i, int j, int n, vector<vector<int>>& traingle, vector<vector<int>> &dp)
    {
        if(i == n)
            return traingle[i][j];
        else
        {
            if(dp[i][j] != -1)
                return dp[i][j];

            int down = traingle[i][j] + helper(i + 1, j, n, traingle, dp);
            int diagonal = traingle[i][j] + helper(i + 1, j + 1, n, traingle, dp);
            dp[i][j] = min(down, diagonal);
            return dp[i][j];
        }
    }
int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(triangle);
    }

TC = O(N * N)
SC = O(N) + O(N * N)

**************************************************TABULATION******************************************

int helper(vector<vector<int>>& traingle)
    {
        int N = traingle.size();
        vector<vector<int>> dp(N, vector<int> (N, 0));
        
        for(int j = 0; j < N; j++)
        {
            dp[N - 1][j] = traingle[N - 1][j];
        }
        for(int i = N - 2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int d = traingle[i][j] + dp[i + 1][j];
                int dg = traingle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(triangle);
    }
TC = O(N * N)
SC = O(N * N)
