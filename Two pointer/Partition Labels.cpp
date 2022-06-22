https://leetcode.com/problems/partition-labels/

*******************************************SOLUTION********************************************

class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> map;
        for(int i = 0; i < s.length(); i++)
        {
            map[s[i]] = i;
        }
        
        vector<int> result;
        
        int start = 0;
        int end = 0;
        int des_start = map[s[start]];
        while(end < s.length())
        {
            if(end < des_start)
            {
                //include all the characters
                char curr_char = s[end];
                //checking the last occuring index of this character
                int last_index_curr_char = map[curr_char];
                if(last_index_curr_char > des_start)
                    des_start = last_index_curr_char;
                end++;
            }
            else if(end == des_start)
            {
                int window_size = end - start + 1;
                result.push_back(window_size);
                //reinitialize start and end , des_start
                start = des_start + 1;
                end = des_start + 1;
                des_start = map[s[start]];
            }
        }
        return result;
    }
};
