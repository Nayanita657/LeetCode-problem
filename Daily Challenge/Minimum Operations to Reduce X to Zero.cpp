https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

*****************************************SOLUTION******************************************

class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sum = 0;
        int max_window = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        
        int temp = sum - x;
        if(temp < 0)
        {
            return -1;
        }
        else if(temp == 0)
        {
            return nums.size();
        }
        else if(temp > 0)
        {
            //find the maximum window with sum as temp
            int start = 0;
            int end = 0;
            while(end < nums.size())
            {
                temp = temp - nums[end];
                if(temp > 0)
                {
                    end++;
                }
                else if(temp == 0)
                {
                    if(max_window < end - start + 1)
                        max_window = end - start + 1;
                    end++;
                }
                else if(temp < 0)
                {
                    while(temp < 0)
                    {
                        temp = temp + nums[start];
                        start++;
                    }
                    if(temp == 0)
                    {
                        if(max_window < end - start + 1)
                            max_window = end - start + 1;
                    }
                    end++;
                }
            }
        }
        if(max_window == INT_MIN)
            return -1;
        else
            return nums.size() - max_window;
    }
};
