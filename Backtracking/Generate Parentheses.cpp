https://leetcode.com/problems/generate-parentheses/

***************************************SOLUTION*******************************

class Solution {
public:
    vector<string> result;
    void helper(int actual_open, int actual_close, int x, int y,string output)
    {
        if(x == 0 && y == 0)
            result.push_back(output);
        else
        {
            //taking open bracket
            if(x != 0)
            {
                output+='(';
                helper(actual_open, actual_close, x - 1, y, output);
                output.pop_back();
            }
            //taking close bracket
            int curr_open = actual_open - x;
            int curr_close = actual_close - y;
            if(curr_open > curr_close)
            {
                output+=')';
                helper(actual_open, actual_close, x, y - 1, output);
                output.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        string output;
        helper(n, n, n, n, output);
        return result;
    }
};
