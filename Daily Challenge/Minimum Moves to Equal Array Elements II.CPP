https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

**************************************SOLUTION***************************************

class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int result = 0;
        sort(nums.begin(),nums.end());
        int target_ele = nums[(nums.size() / 2)];
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = nums[i] - target_ele;
            if(diff < 0)
                diff = -(diff);
            result = result + diff;
        }
        return result;
    }
};
