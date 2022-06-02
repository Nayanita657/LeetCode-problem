https://www.lintcode.com/problem/659/

******************************************************SOLUTION*******************************************

class Solution 
{
public:
    
    string encode(vector<string> &strs) 
    {
        string encoded_string;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            encoded_string += to_string(temp.length());
            encoded_string += '$';
            encoded_string = encoded_string + temp;
        }
        return encoded_string;
    }

    
    vector<string> decode(string &str) 
    {
        vector<string> decoded_string;
        for(int i = 0; i < str.length(); i++)
        {
            string store;
            int k = i;
            while(str[k] != '$')
            {
                store += str[k];
                k++;
            }
            int size = stoi(store);
            string temp;
            for(int j = k + 1; j <= k + size; j++)
            {
                temp += str[j];
                
            }
            decoded_string.push_back(temp);
            i = k + size;
        }
        return decoded_string;
    }
};
