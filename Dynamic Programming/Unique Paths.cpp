https://leetcode.com/problems/unique-paths/

*****************************SOLUTION**********************************

int helper(int start_row, int start_col, int target_row, int target_col, vector<vector<int>>& dp)
    {
        //base condition
        if(start_row > target_row || start_col > target_col)
            return 0;
        else if(dp[start_row][start_col] != -1)
            return dp[start_row][start_col];
        else if(start_row == target_row && start_col == target_col)
            return 1;
    
        else
        {
            //calling to right side
            int val1 = helper(start_row, start_col + 1, target_row, target_col, dp);
            //calling to buttom side
            int val2 = helper(start_row + 1, start_col, target_row, target_col, dp);
            
            dp[start_row][start_col] = val1 + val2;
            
            return dp[start_row][start_col];
        }
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp;
        for(int i = 0; i < m; i++)
        {
            vector<int> inner_result;
            for(int j = 0; j < n; j++)
                inner_result.push_back(-1);
            
            dp.push_back(inner_result);
        }
        return helper(0, 0, m - 1, n - 1,dp);
        
    }
