https://leetcode.com/problems/combination-sum-ii/

***********************************SOLUTION**********************************

class Solution {
public:
    vector<vector<int>> result;
    
    void helper(int start_index, vector<int>& input, int target, vector<int>& output)
    {
        if(start_index == input.size())
        {
            if(target == 0)
                result.push_back(output);
        }
        else if(target == 0)
        {
            result.push_back(output);
        }
        else if(target < 0)
        {
            return;
        }
        else
        {
            int curr_ele = INT_MIN;
            for(int i = start_index; i < input.size(); i++)
            {
                if(curr_ele == INT_MIN)
                {
                    curr_ele = input[i];
                    output.push_back(input[i]);
                    helper(i + 1, input, target - input[i], output);
                    output.pop_back();
                }
                else
                {
                    if(input[i] != curr_ele)
                    {
                        curr_ele = input[i];
                        output.push_back(input[i]);
                        helper(i + 1, input, target - input[i], output);
                        output.pop_back();
                    }
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& input, int target) 
    {
        vector<int> output;
        sort(input.begin(), input.end());
        helper(0, input, target, output);
        return result;
    }
};
