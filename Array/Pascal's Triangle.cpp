https://leetcode.com/problems/pascals-triangle/

***************************************SOLUTION**********************************

vector<vector<int>> generate(int numsRows) 
    {
        vector<vector<int>> result;
        for(int i = 0; i < numsRows; i++)
        {
            vector<int> inner_result(i + 1, 1);
            for(int j = 1; j < i; j++)
            {
                inner_result[j] = result[i - 1][j] + result[i - 1][j - 1];
            }
            result.push_back(inner_result);
        }
        return result;
    }

TC = O(N ^ 2) 
SC = O(1)
