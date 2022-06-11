https://leetcode.com/problems/kth-largest-element-in-an-array/

***************************************SOLUTION***************************************

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i = 0; i < nums.size(); i++)
        {
            if(p.empty())
                p.push(nums[i]);
            else
            {
                if(p.size() < k)
                    p.push(nums[i]);
                else if(p.size() == k)
                {
                    if(nums[i] > p.top())
                    {
                        p.pop();
                        p.push(nums[i]);
                    }
                }
            }
        }
        return p.top();
    }
};
