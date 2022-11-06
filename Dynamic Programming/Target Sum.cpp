https://bit.ly/3swy5uL

****************************************************GENERAL APPROACH******************************************

 int helper(int ind, int curr_sum, int target, vector<int>& arr)
    {
        if(ind == 0)
        {
            if(arr[0] == 0 )
            {
                if(curr_sum == target)
                    return 2;
                else
                    return 0;
            }
            else
            {
                if((curr_sum + arr[0]) == target || (curr_sum - arr[0]) == target)
                    return 1;
                else
                    return 0;
            }
           
        }
        else
        {
            int positive = helper(ind - 1, curr_sum + arr[ind], target, arr);
            int negative = helper(ind - 1, curr_sum - arr[ind], target, arr);
            return positive + negative;
        }
    }
    int targetSum(int n, int target, vector<int>& arr) 
    {
        return helper(n - 1, 0, target, arr);
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        return targetSum(n , target, nums);
    }

****************************************************************************************************************************************

THE APPROACH OF THIS QUESTION IS SIMILAR WITH THE PROBLEM PARTITIONS WITH GIVEN DIFFERENCE
