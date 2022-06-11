https://leetcode.com/problems/longest-happy-string/

********************************************SOLUTION******************************************

class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int,char>> p;
        
        if(a != 0)
            p.push(make_pair(a,'a'));
        if(b != 0)
            p.push(make_pair(b,'b'));
        if(c != 0)
            p.push(make_pair(c,'c'));
        
        string result = "";
        int index = 0;
        while(p.size() > 1)
        {
            pair<int,char> temp = p.top();
            if(result.length() < 2)
            {
                result+=temp.second;
                index++;
                p.pop();
                if(temp.first - 1 != 0)
                    p.push(make_pair(temp.first - 1,temp.second));
            }
            else
            {
                if(result[index - 2] == temp.second && result[index - 1] == temp.second)
                {
                    //take the second maximum from the heap
                    //store the first maximum in the another variable
                    pair<int,char> first_max = p.top();
                    p.pop();
                    //store the second maximum 
                    pair<int,char> second_max = p.top();
                    result+=second_max.second;
                    index++;
                    p.pop();
                    if(second_max.first - 1 != 0)
                        p.push(make_pair(second_max.first - 1,second_max.second));
                    if(first_max.first != 0)
                        p.push(make_pair(first_max.first,first_max.second));
                }
                else
                {
                    result+=temp.second;
                    index++;
                    p.pop();
                    if(temp.first - 1 != 0)
                        p.push(make_pair(temp.first - 1,temp.second));
                }
            }
        }
        if(p.size() == 1)
        {
            pair<int,char> temp = p.top();
            if(temp.first >= 2)
            {
                //simply append the character twice
                result+=temp.second;
                result+=temp.second;
            }
            else
            {
                result+=temp.second;
            }
        }
        return result;
    }
};
