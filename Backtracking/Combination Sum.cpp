https://leetcode.com/problems/combination-sum/

**************************************SOLUTION********************************************

class Solution {
public:
    
    vector<vector<int>> result;
    
    void helper(vector<int> input, vector<int> output, int target)
    {
        if(input.size() == 0 || target < 0)
        {
            return;
        }
        else if(target == 0)
        {
            result.push_back(output);
        }
        else
        {
            //taking the input 
            output.push_back(input[0]);
            helper(input, output, target - input[0]);
            //not taking input
            
            output.pop_back();
            int start = 1;
            int length = input.size();
            int end = length - 1;
            auto first = input.cbegin() + start;
            auto last = input.cbegin() + end + 1;
            vector<int> vec1(first, last);
            helper(vec1, output, target);
           
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& input, int target) 
    {
        vector<int> output;
        helper(input, output, target);
        return result;
    }
};
