https://leetcode.com/problems/house-robber-ii/description/

************************************************MEMOIZATION**********************************************

class Solution {
public:

    int helper1(int ind, vector<int> nums, vector<int>& dp)
    {
        if(ind == 0)
            return nums[0];
        else if(ind < 0)
            return 0;
        else
        {
            if(dp[ind] != -1)
                return dp[ind];
            int pick = nums[ind] + helper1(ind - 2, nums, dp);
            int nonpick = 0 + helper1(ind - 1, nums, dp);
            dp[ind] = max(pick, nonpick);
            return dp[ind];
        }
    }
    int rob(vector<int>& nums) 
    {

        if(nums.size() == 1)
            return nums[0];

            
        //removing the last element from the array
        vector<int> dp1(nums.size(), -1);
        int val1 = helper1(nums.size() - 2, nums, dp1);
        cout<<val1<<endl;
        //removing the first element from the array
        vector<int>::iterator it;
        it = nums.begin();
        nums.erase(it);
        vector<int> dp2(nums.size(), -1);
        int val2 = helper1(nums.size() - 1, nums, dp2);
        cout<<val2<<endl;
        return max(val1, val2);
    }
};
