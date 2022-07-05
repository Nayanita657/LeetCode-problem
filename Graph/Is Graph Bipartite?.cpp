https://leetcode.com/problems/is-graph-bipartite/

*********************************SOLUTION*******************************

class Solution {
public:
    bool bfs(int curr_node, vector<vector<int>>& graph, vector<int>& color)
    {
        color[curr_node] = 0;
        queue<int> pendingQueue;
        pendingQueue.push(curr_node);
        while(!pendingQueue.empty())
        {
            int front = pendingQueue.front();
            pendingQueue.pop();
            for(int j = 0; j < graph[front].size(); j++)
            {
                int adj_node = graph[front][j];
                if(color[adj_node] == -1)
                {
                    //color it with oposite color
                    color[adj_node] = 1 - color[front];
                    pendingQueue.push(adj_node);
                }
                else
                {
                    if(color[adj_node] == color[front])
                    {
                        return false;
                    }
                } 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i = 0; i < V; i++)
        {
            if(color[i] == -1)
            {
               bool result = bfs(i, graph, color);
               if(result == false)
                    return false;
            }
        }
        return true;
    }
};
