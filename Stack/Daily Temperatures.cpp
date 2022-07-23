https://leetcode.com/problems/daily-temperatures/

******************************SOLUTION**************************************

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            if(st.empty())
            {
                result[i] = 0;
                st.push(i);
            }
            else
            {
                int curr_ele = temperatures[i];
                if(curr_ele < temperatures[st.top()])
                {
                    int diff = st.top() - i;
                    result[i] = diff;
                    st.push(i);
                }
                else
                {
                    //pop until we get large element in stack
                    while(!st.empty() && temperatures[st.top()] <= curr_ele)
                    {
                        st.pop();
                    }
                    if(st.empty())
                    {
                        //curr_ele is the highest element
                        result[i] = 0;
                        st.push(i);
                    }
                    else
                    {
                        //higher element exist 
                        int diff = st.top() - i;
                        result[i] = diff;
                        st.push(i);
                    }
                    //lastly push the current element
                }
                
            }
        }
        
        return result;
    }
};
