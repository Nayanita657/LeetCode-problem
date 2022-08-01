https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

********************************************SOLUTION**************************************

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;
    void merging(vector<long long>& part1, vector<long long>& part2, vector<long long>& nums)
    {
        int k = 0;
        int i = 0;
        int j = 0;
        
        while(i < part1.size() && j < part2.size())
        {
            if(part1[i] <= part2[j])
            {
                nums[k] = part1[i];
                i++;
                k++;
            }
            else
            {
                count = count + (part1.size() - i);
                nums[k] =part2[j];
                j++;
                k++;
            }
        }
        
        while(i < part1.size())
        {
            nums[k] = part1[i];
            i++;
            k++;
        }
        
        while(j < part2.size())
        {
            nums[k] = part2[j];
            j++;
            k++;
        }
        
    }
    
    void helper(vector<long long>& nums)
    {
        if(nums.size() <= 1)
            return;
        
        vector<long long> part1;
        vector<long long> part2;
        
        long long mid = nums.size() / 2;
        long long size1 = mid;
        long long size2 = nums.size() - mid;
        
        for(int i = 0; i < size1; i++)
        {
            part1.push_back(nums[i]);
        }
        
        for(int j = size1; j < nums.size(); j++)
        {
            part2.push_back(nums[j]);
        }
        
        helper(part1);
        helper(part2);
        merging(part1, part2, nums);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        vector<long long> input(arr, arr + N);
        helper(input);
        return count;
        
    }

};
