https://leetcode.com/problems/single-number/


********************************SOLUTION***********************************

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;
        int i = 0;
        while(i < nums.size())
        {
            result = result ^ nums[i];
            i++;
        }
        return result;
    }
};
