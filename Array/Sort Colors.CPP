https://leetcode.com/problems/sort-colors/

******************************SOLUTION******************************

The solution is solved using Dutch National Flag

void sortColors(vector<int>& nums) 
    {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while(mid <= end)
        {
            if(nums[mid] == 0)
            {
                int temp = nums[mid];
                nums[mid] = nums[start];
                nums[start] = temp;
                start++;
                mid++;
            }
            else if(nums[mid] == 2)
            {
                //swap with end
                int temp = nums[mid];
                nums[mid] = nums[end];
                nums[end] = temp;
                
                //if after swapping we get 0 then we have to place correct position
                if(nums[mid] == 0)
                {
                    //swapping with start
                    int temp = nums[mid];
                    nums[mid] = nums[start];
                    nums[start] = temp;
                    start++;
                }
                end--;
                //mid++;
            }
            else
                mid++;
        }
    }


TC = O(N)
SC = O(1)
