https://leetcode.com/problems/maximum-erasure-value/

*******************************************SOLUTION**********************************

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int start = 0;
        int end = 0;
        unordered_map<int,int> map;
        int sum = 0;
        int max_sum = INT_MIN;
        while(end < nums.size())
        {
            map[nums[end]]++;
            sum = sum + nums[end];
            if(map.size() == (end - start + 1))
            {
                if(max_sum < sum)
                    max_sum = sum;
                end++;
            }
            else if(map.size() < (end - start + 1))
            {
                //remove the occurence of all the elements till the duplicate element
                while(nums[start] != nums[end])
                {
                    //remove the elementS before the start index
                    map[nums[start]]--;
                    if(map[nums[start]] == 0)
                        map.erase(nums[start]);
                    sum = sum - nums[start];
                    start++;
                }
                //remove the perticular occured element
                map[nums[start]]--;
                sum = sum - nums[start];
                start++;
                if(map.size() == (end - start + 1))
                {
                    if(max_sum < sum)
                        max_sum = sum;
                    end++;
                }
                
            }
        }
        return max_sum;
    }
};
