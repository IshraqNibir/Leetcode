class Solution {
public:
    vector<int>adj[2005];
    int color[2005];
    vector<int>order;
    
    bool dfs(int v) {
        color[v] = 1;
        for(int i=0; i<adj[v].size(); i++) {
            int node = adj[v][i];
            if (color[node] == 0) {
                if (dfs(node))
                    return true;
            } 
            else if (color[node] == 1) {
                return true;
            }
        }
        color[v] = 2;
        order.push_back(v);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(color, 0, sizeof(color));
        
        for (int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        bool answer = true;
        for (int v = 0; v < numCourses; v++) {
            if (color[v] == 0 && dfs(v)) {
                answer = false;
                break;
            }
        }
        
        reverse(order.begin(), order.end());
        if (!answer) {
            order.clear();
        }
        return order;
    }
};
