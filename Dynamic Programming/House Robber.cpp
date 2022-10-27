https://leetcode.com/problems/house-robber/description/

**************************************RECURSION*************************************************************

int helper1(int index, vector<int> nums)
    {
        if(index == 0)
            return nums[index];
        else if(index < 0)
            return 0;
        else
        {
            int pick = nums[index] + helper1(index - 2, nums);
            int nonpick = 0 + helper1(index - 1, nums);
            return max(pick, nonpick);
        }
    }
int rob(vector<int>& nums) 
    {
        return helper(nums.size() - 1, nums);
    }

TC = O(2^N)
**********************************MEMOIZATION*******************************************************

 int helper1(int index, vector<int> nums, vector<int> &dp)
    {
        if(index == 0)
            return nums[index];
        else if(index < 0)
            return 0;
        else
        {
            if(dp[index] != -1)
                return dp[index];

            int pick = nums[index] + helper1(index - 2, nums, dp);
            int nonpick = 0 + helper1(index - 1, nums, dp);
            dp[index] = max(pick, nonpick);
            return dp[index];
        }
    }

int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), -1);
        return helper1(nums.size() - 1, nums, dp);
    }
TC = O(N)
SC = O(N) + O(N)
*****************************************TABULATION*******************************************

int helper2(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> dp(N, 0);
        dp[0] = nums[0];
        for(int i = 1; i < N; i++)
        {
            int pick = nums[i];
            if(i > 1)
                pick+=dp[i - 2];
            int nonpick = 0 + dp[i - 1];
            dp[i] = max(pick, nonpick);
        }
        return dp[N - 1];
    }
int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), -1);
        return helper2(nums);
    }
TC = O(N)
SC = O(N)
