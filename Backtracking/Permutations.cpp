https://leetcode.com/problems/permutations/

*********************************SOLUTION***********************************
class Solution {
public:
    vector<vector<int>> result;
    
    void helper(vector<int> input, vector<int> output, int size, unordered_map<int,int> map)
    {
        if(output.size() == size)
            result.push_back(output);
        else
        {
            for(int i = 0; i < input.size(); i++)
            {
                int curr_ele = input[i];
                if(map[curr_ele] != 0)
                {
                    output.push_back(curr_ele);
                    map[curr_ele]--;
                    helper(input, output, size, map);
                    map[curr_ele]++;
                    output.pop_back();
                }
                
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> output;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        
        helper(nums, output, nums.size(), map);
        
        return result;
    }
};
