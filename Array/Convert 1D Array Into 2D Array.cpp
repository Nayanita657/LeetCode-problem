https://leetcode.com/problems/convert-1d-array-into-2d-array/

**********************************SOLUTION**********************************

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        if(original.size() != (m * n))
            return {};
        
        int i = 0;
        int row = 1;
        vector<vector<int>> result;
        while(row <= m)
        {
            vector<int> inner_result;
            for(int column = 1; column <= n; column++)
            {
                inner_result.push_back(original[i]);
                i++;
                    
            }
            result.push_back(inner_result);
            row++;
        }
        
        //result.push_back(inner_result);
        return result;
    }
};
