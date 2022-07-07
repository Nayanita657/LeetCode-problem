https://leetcode.com/problems/plus-one/

***********************************SOLUTION************************************

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int size = digits.size();
        int i = size - 1;
        int carry = 0;
        while(i >= 0)
        {
            int sum;
            if(i == size - 1)
            {
                sum = digits[i] + 1;
            }
            else
            {
                sum = digits[i] + carry;
            }
            
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
                
            }
            else
            {
                carry = 0;
            }
            digits[i] = sum;
            i--;
        }
        
        if(carry == 1)
            digits.insert(digits.begin(),carry);
        
        return digits;
    }
};
