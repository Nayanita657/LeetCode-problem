https://leetcode.com/problems/find-median-from-data-stream/

***************************************SOLUTION**************************************

class MedianFinder {
public:
    priority_queue<int> max_heap;//small heap
    priority_queue<int,vector<int>,greater<int>> min_heap;//large heap
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        //default insert in max_heap
        max_heap.push(num);
        
        if(max_heap.size() > min_heap.size())
        {
            if((max_heap.size() - min_heap.size()) > 1)
            {
                //remove the max element from the small heap
                int temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
            }
        }
        else if(min_heap.size() > max_heap.size())
        {
            if((min_heap.size() - max_heap.size()) > 1)
            {
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
        }
        
        //every element in the small heap should be small than the min heap
        if(!min_heap.empty() && max_heap.top() > min_heap.top())
        {
            //remove the max element from small heap and insert it in large heap
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
            if(min_heap.size() > max_heap.size())
            {
                if((min_heap.size() - max_heap.size()) > 1)
                {
                    int temp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                }
            }
            
        }
        
    }
    
    double findMedian() 
    {
        double result;
        if(min_heap.size() == 0)
            result = max_heap.top();
        else
        {
            if(max_heap.size() == min_heap.size())
            {
                double val1 = max_heap.top();
                double val2 = min_heap.top();
                result = (val1 + val2) / 2;
            }
            else if(max_heap.size() > min_heap.size())
            {
                result = max_heap.top();
            }
            else if(min_heap.size() > max_heap.size())
            {
                result = min_heap.top();
            }
        }
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
