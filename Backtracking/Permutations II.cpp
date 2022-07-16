https://leetcode.com/problems/permutations-ii/

************************************SOLUTION***************************************


class Solution {
public:
    
    vector<vector<int>> result;
    unordered_map<int,int> map;
    
    void helper(unordered_map<int, int>& map, int size, vector<int> output)
    {
        if(output.size() == size)
        {
            result.push_back(output);
            return;
        }
        else
        {
            unordered_map<int,int> :: iterator itr;
            for(itr = map.begin(); itr != map.end(); itr++)
            {
                int val = itr->first;
                if(map[val] != 0)
                {
                    output.push_back(val);
                    map[val]--;
                    helper(map, size, output);
                    output.pop_back();
                    map[val]++;
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<int> output;
        for(int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        
        helper(map, nums.size(), output);
        return result;
    }
};
