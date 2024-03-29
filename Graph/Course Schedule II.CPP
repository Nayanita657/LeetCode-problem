https://leetcode.com/problems/course-schedule-ii/

***********************SOLUTION********************************

class Solution {
public:
    void TopologicalSort(int curr_num,  vector<int> adj[], vector<int>& visited, stack<int>& st)
    {
        visited[curr_num] = 1;
        for(auto it = adj[curr_num].begin(); it != adj[curr_num].end(); it++)
        {
            if(visited[*it] != 1)
                TopologicalSort(*it, adj, visited, st);
        }
        st.push(curr_num);
    }
    
    bool cycle(int node,vector<bool> &vis,vector<bool> &dfsvis,vector<int> adj[])
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(cycle(it,vis,dfsvis,adj)) return true;
            }else if(dfsvis[it]==1) return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool> vis(v,0);
        vector<bool> dfsvis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(cycle(i,vis,dfsvis,adj)) return true;
            }
        }
        return false;
    }
    vector<int> findOrder(int numCourses1, vector<vector<int>>& numCourses) 
    {
        int V = numCourses1;
        int E = numCourses.size();
        vector<int> adj[V];
        vector<int> final_result;
        for(int i = 0; i < E; i++)
        {
            int v1 = numCourses[i][0];
            int v2 = numCourses[i][1];
            adj[v2].push_back(v1);
        }
        bool iscycle = isCyclic(V, adj);
        if(iscycle)
            return {};
        else
        {
            //checking for topological sort
            vector<int> visited(V, 0);
            stack<int> st;
            for(int i = 0; i < V; i++)
            {
                if(visited[i] != 1)
                    TopologicalSort(i, adj, visited, st);
            }
       
            if(st.size() != V)
                return {};
            else
            {
                while(st.size() != 0)
                {
                    final_result.push_back(st.top());
                    st.pop();
                }
                return final_result;
            }
        
        }
    }
};
