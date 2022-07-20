https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

*********************************SOLUTION***************************************

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            int curr_num = nums[i];
            if(curr_num < 0)
                curr_num = -(curr_num);
            
            int next_ind = curr_num - 1;
            
            //change the value in next index
            if(nums[next_ind] > 0)
                nums[next_ind] = -(nums[next_ind]);
        }
        
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                result.push_back(i+1);
        }
        return result;
    }
};
