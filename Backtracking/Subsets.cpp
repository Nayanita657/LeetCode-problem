https://leetcode.com/problems/subsets/

**********************************SOLUTION********************************

class Solution {
public:
    
    vector<vector<int>> result;
    
    void helper(vector<int> input, vector<int> output)
    {
        if(input.size() == 0)
        {
            vector<int> temp;
        
            if(result.size() != 0)
            {
                for(int i = 0; i < output.size(); i++)
                    temp.push_back(output[i]);
            }
            result.push_back(temp);
        }
        else
        {
            int start = 1;
            int length = input.size();
            int end = length - 1;
            auto first = input.cbegin() + start;
            auto last = input.cbegin() + end + 1;
            vector<int> vec1(first, last);
            //without taking input;
            helper(vec1, output);
            //taking input
            output.push_back(input[0]);
            helper(vec1, output);
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& input) 
    {
        vector<int> output;
        helper(input, output);
        return result;
    }
};
