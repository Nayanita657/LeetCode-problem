https://leetcode.com/problems/maximum-units-on-a-truck/

*******************************************SOLUTION***************************************************
class Solution {
public:
    static bool comparator(const vector<int>& p1, const vector<int>& p2)
    {
        return p1[1] > p2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int max_profit = 0;
        //sort the vector on the basis of numberOfUnitsPerBoxi
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int i = 0;
        while(truckSize > 0 && i < boxTypes.size())
        {
            int numberOfBoxes = boxTypes[i][0];
            if(truckSize >= numberOfBoxes)
            {
                max_profit = max_profit + (numberOfBoxes * boxTypes[i][1]);
                truckSize = truckSize - numberOfBoxes;
            }
            else
            {
                max_profit = max_profit + (truckSize * boxTypes[i][1]);
                truckSize = 0;
            }
            i++;
        }
        return max_profit;
    }
};
