https://leetcode.com/problems/unique-paths/


https://leetcode.com/problems/unique-paths/

********************************************RECURSION*********************************************

int helper(int i, int j)
    {
        if(i == 0 && j == 0)
            return 1;
        else if(i < 0 || j < 0)
            return 0;
        else
        {
            int up = helper(i - 1, j);
            int down = helper(i, j - 1);
            return up + down;
        }
    }
    int uniquePaths(int m, int n) 
    {
        return helper(m - 1, n - 1);    
    }

TC = O(2 ^ (M*N)) WHERE M*N IS THE NUMBER OF CELLS IN THE GRID
SC = O((M - 1) + (N - 1)) //LENGTH OF THE PATH


*****************************************MEMOIZATION*************************************************
int helper(int i, int j, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
            return 1;
        else if(i < 0 || j < 0)
            return 0;
        else
        {
            if(dp[i][j] != -1)
                return dp[i][j];

            int up = helper(i - 1, j, dp);
            int down = helper(i, j - 1, dp);
            dp[i][j] = up + down;
            return dp[i][j];
        }
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);    
    }
TC = O(M * N)
SC = O((M - 1) + (N - 1)) + (M * N)) //LENGTH OF PATH + 2d DP ARRAY
**************************************TABULATION*******************************************************

int helper(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                    

                int up;
                if((i - 1) < 0)
                    up = 0;
                else
                    up = dp[i - 1][j];

                int down;
                if((j - 1) < 0)
                    down = 0;
                else
                    down = dp[i][j - 1];
                
                dp[i][j] = up + down;

            }
        }
        return dp[m - 1][n - 1];
    }
int uniquePaths(int m, int n) 
    {        
        return helper(m, n);  
    }

TC = O(M * N)
SC = O(M * N)
