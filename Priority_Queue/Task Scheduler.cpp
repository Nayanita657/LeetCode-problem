https://leetcode.com/problems/task-scheduler/

*******************************SOLUTION*************************************

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if(n == 0)
            return tasks.size();
        else
        {
            priority_queue<pair<int,char>> pq;
            queue<pair<pair<int,char>,int>> queue;
            int result = 0;
            unordered_map<char,int> map;
            for(int i = 0; i < tasks.size(); i++)
            {
                map[tasks[i]]++;
            }
            unordered_map<char,int> :: iterator itr;
            for(itr = map.begin(); itr != map.end(); itr++)
            {
                pair<int,char> temp;
                temp.first = itr->second;
                temp.second = itr->first;
                pq.push(temp);
            }
            while(!pq.empty() || !queue.empty())
            {
                if(queue.size() == 0)
                {
                    pair<int,char> temp = pq.top();
                    result++;
                    pq.pop();
                    temp.first = temp.first - 1;
                    if(temp.first != 0)
                    {
                        //insert the element in the queue
                        pair<pair<int,char>,int> dep;
                        dep.first.first = temp.first;
                        dep.first.second = temp.second;
                        dep.second = result + n;
                        queue.push(dep);
                    }
                }
                else
                {
                    pair<pair<int,char>,int> front_ele = queue.front();
                    if(result == front_ele.second)
                    {
                        queue.pop();
                        pair<int,char> new_ele;
                        new_ele.first = front_ele.first.first;
                        new_ele.second = front_ele.first.second;
                        pq.push(new_ele);
                    }
                    if(pq.empty())
                    {
                        result++;//idle time
                    }
                    else
                    {
                        //extract the next max from heap
                        pair<int,char> temp = pq.top();
                        result++;
                        pq.pop();
                        temp.first = temp.first - 1;
                        if(temp.first != 0)
                        {
                            //insert the element in the queue
                            pair<pair<int,char>,int> dep;
                            dep.first.first = temp.first;
                            dep.first.second = temp.second;
                            dep.second = result + n;
                            queue.push(dep);
                        }
                    }
                }
            }
            return result;
        }
        
    }
};
