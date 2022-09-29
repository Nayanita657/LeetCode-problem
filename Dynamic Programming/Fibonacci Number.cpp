https://leetcode.com/problems/fibonacci-number/description/

************************Normal Recursion solution***********************
int fib(int n) 
    {
        if(n == 0 || n == 1)
            return n;
        else
        {
            return fib(n - 1) + fib(n - 2);
        }
        
    }
TC = O(2^N)   
SC = O(N)
  
***********************Memoization****************************************
int helper(int n, vector<int>& dp)
    {
        if(n <= 1)
            return n;
        else if(dp[n] != -1)
            return dp[n];
        else
            return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    int fib(int n) 
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
TC = O(N)
SC = O(N) + O(N)[recursion stack + dynamic array]

***********************Tabulation******************************************
int helper(int n, vector<int>& dp)
    {
        dp[0] = 0;
        if(n == 0)
            return dp[n];
        dp[1] = 1;
        if(n == 1)
            return dp[n];
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            
        }  
        return dp[n];
    }
    int fib(int n) 
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }

TC = O(N)
SC = O(N)
