https://leetcode.com/problems/sort-colors/

*******************************************SOLUTION****************************************

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int mid = 0;
        int start = 0;
        int end = nums.size() - 1;
        while(mid <= end)
        {
            if(nums[mid] == 0)
            {
                //do swapping with nums[start]
                int temp = nums[start];
                nums[start] = nums[mid];
                nums[mid] = temp;
                mid++;
                start++;
            }
            else if(nums[mid] == 2)
            {
                //do swapping with nums[end]
                int temp = nums[end];
                nums[end] = nums[mid];
                nums[mid] = temp;
                //again check for nums[mid] == 0 condition
                if(start != 0 && nums[mid] == 0)
                {
                    //once swapping is done for nums[end] then again swap with nums[start]
                    int temp = nums[start];
                    nums[start] = nums[mid];
                    nums[mid] = temp;
                    start++;
                }
                mid++;
                end--;
            }
            else
            {
                mid++;
            }
        }
    }
};
