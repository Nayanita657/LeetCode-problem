https://leetcode.com/problems/combination-sum-iii/

***********************************SOLUTION****************************


vector<vector<int>> result;
    
    void helper(int start_index, vector<int> input, int target_size,int target, vector<int> output)
    {
        if(output.size() > target_size)
            return;
        else if(start_index == input.size())
        {
            if(output.size() == target_size && target == 0)
                result.push_back(output);
        }
        else if(target < 0)
            return;
        else if(output.size() == target_size)
        {
            if(target == 0)
                result.push_back(output);
        }
            
        else
        {
            
            //taking the input
            output.push_back(input[start_index]);
            helper(start_index + 1, input, target_size, target - input[start_index], output);
            output.pop_back();
            
            //withpt taking the input
            helper(start_index + 1, input, target_size, target, output);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        
        vector<int> output;
        vector<int>input;
        for(int i = 1; i <= 9 ; i++)
            input.push_back(i);
        
        helper(0, input, k, n, output);
        return result;
    }
