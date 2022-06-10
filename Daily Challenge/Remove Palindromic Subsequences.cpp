https://leetcode.com/problems/remove-palindromic-subsequences/
*********************************SOLUTION***************************************

class Solution {
public:
    bool is_palindrome(string str)
    {
        int start = 0;
        int end = str.length() - 1;
        while(start < end)
        {
            if(str[start] == str[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) 
    {
        if(s.length() == 0)
            return 0;
        if(is_palindrome(s))
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};
