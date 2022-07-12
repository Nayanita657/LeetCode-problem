https://leetcode.com/problems/subsets-ii/

******************************SOLUTION*****************************

class Solution {
public:
    
    vector<vector<int>> result;
    unordered_map<string, int> map;
    
    void helper(vector<int> input, vector<int> output)
    {
        if(input.size() == 0)
        {
            vector<int> temp;
        
            if(result.size() != 0)
            {
                string check;
                for(int i = 0; i < output.size(); i++)
                {
                    temp.push_back(output[i]);
                    //char ch = to_string(output[i]);
                    check+=to_string(output[i]);
                }
                map[check]++;
                if(map[check] == 1)
                    result.push_back(temp);
            }
            else
            {
                result.push_back(temp);
            }
            
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
    
    vector<vector<int>> subsetsWithDup(vector<int>& input) 
    {
        sort(input.begin(),input.end());
        vector<int> output;
        helper(input, output);
        return result;
    }
};
