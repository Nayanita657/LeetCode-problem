https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

*************************************SOLUTION*****************************************

USING RECURSION
____________________________________________________________________________________________________________________________________________________________
int helper(int curr_ind, vector<int> heights)
{
    if(curr_ind == 0)
        return 0;
    else
    {
        int ans1 = helper(curr_ind - 1, heights) + abs(heights[curr_ind] - heights[curr_ind - 1]);
        int ans2 = INT_MAX;
        if((curr_ind - 2) >= 0)
            ans2 = helper(curr_ind - 2, heights) + abs(heights[curr_ind] - heights[curr_ind - 2]);
        return min(ans1, ans2);
    }
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return helper(n - 1, heights);
    
}
TC = O(2^N)

USING MEMOIZATION(DYNAMIC PROGRAMMING)
____________________________________________________________________________________________________________________________________________________________
int helper(int curr_ind, vector<int> heights, vector<int>& dp)
{
    if(curr_ind == 0)
        return 0;
    else
    {
        if(dp[curr_ind] != -1)
            return dp[curr_ind];
        int ans1 = helper(curr_ind - 1, heights) + abs(heights[curr_ind] - heights[curr_ind - 1]);
        int ans2 = INT_MAX;
        if((curr_ind - 2) >= 0)
            ans2 = helper(curr_ind - 2, heights) + abs(heights[curr_ind] - heights[curr_ind - 2]);
        dp[curr_ind] = min(ans1, ans2);
        return dp[curr_ind];
    }
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return helper(n - 1, heights, dp);
    
}  
TC = O(N)
