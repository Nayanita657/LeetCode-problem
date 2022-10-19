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

USING MEMOIZATION(DYNAMIC PROGRAMMING) [TOP DOWN APPROACH]
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
SC = O(N)
USING TABULATION(DYNAMIC PROGRAMING) [BUTTOM-UP APPROACH]
________________________________________________________________________________________________
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);

    // Already at last stair.
    dp[n] = 0;

    // Only choice to take a single gap jump.
    dp[n - 1] = abs(heights[n - 2] - heights[n - 1]);

    for(int i = n-2; i > -1; i--){

        int oneJump = dp[i + 1] + abs(heights[i - 1] - heights[i]);
        int twoJump = dp[i + 2] + abs(heights[i - 1] - heights[i + 1]);

        dp[i] = min(oneJump, twoJump);
    }

    int ans = dp[1];
    return ans;
}
TC = O(N)
SC = O(N) {STACK SPACE + DP ARRAY]
