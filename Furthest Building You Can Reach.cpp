https://leetcode.com/problems/furthest-building-you-can-reach/

********************************************SOLUTION********************************************

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int count = 0;
        int curr_height = heights[0];
        for(int i = 1; i < heights.size(); i++)
        {
            int next_height = heights[i];
            if(curr_height < next_height)
            {
                int diff = next_height - curr_height;
                if((bricks == 0 || diff > bricks) && ladders != 0)
                {
                    ladders--;
                    count++;
                }
                else if(bricks != 0)
                {
                    bricks = bricks - diff;
                    count++;
                }
                else
                    break;
            }
            else
            {
                count++;
            }
            
            curr_height = heights[i];
        }
        
        return count;
    }
};
