https://leetcode.com/problems/minimum-path-sum/

***************************************************RECURSION************************************

int helper(int i, int j, vector<vector<int>> &grid)
    {
        if(i == 0 && j == 0)
            return grid[i][j];
        else if(i < 0 || j < 0)
            return 1e9;
        else
        {
   
            int up = grid[i][j] + helper(i - 1, j, grid);
            int left = grid[i][j] + helper(i, j - 1, grid);
            return min(up, left);
        }
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();     
        return helper(m - 1, n - 1, grid);   
    }

TC = O(2 ^ (M*N))
SC = O((M - 1) + (N - 1)) //PATH LENGTH

*****************************************MEMOIZATION*****************************************

 int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return grid[i][j];
        else if(i < 0 || j < 0)
            return 1e9;
        else
        {
            if(dp[i][j] != -1)
                return dp[i][j];

            int up = helper(i - 1, j, grid, dp);
            int left = helper(i, j - 1, grid, dp);
            
            if(up == INT_MAX && left == INT_MAX)
                return dp[i][j] = INT_MAX;
            else if(up == INT_MAX && left != INT_MAX)
                return dp[i][j] = grid[i][j] + left;
            else if(up != INT_MAX && left == INT_MAX)
                return dp[i][j] = grid[i][j] + up;
            else
                return dp[i][j] = grid[i][j] + min(up, left);
                
            dp[i][j] = min(up, left);
            return dp[i][j];
        }
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m - 1, n - 1, grid, dp);   
    }
TC = O(M * N)
SC = O((M - 1) + (N - 1)) + (M * N)) //DP ARRAY && STACK SPACE
  
******************************************TABULATION*********************************************

int helper(int m, int n, vector<vector<int>>& grid)
    {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = grid[i][j];
                if(i - 1 < 0)
                    up+=1e7;
                else
                    up+=dp[i - 1][j];

                int left = grid[i][j];
                if(j - 1 < 0)
                    left+=1e7;
                else
                    left+=dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
int minPathSum(vector<vector<int>>& grid) 
    {

        int m = grid.size();
        int n = grid[0].size();
        return helper(m, n, grid);
    }

TC = O(M * N)
SC = O(M * N)
