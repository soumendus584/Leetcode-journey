class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited, vector<int>& component) {

        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        // Build graph
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                vector<int> component;

                dfs(i, adj, visited, component);

                int size = component.size();
                bool complete = true;

                // Every node must connect to all other
                // nodes in this component
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    ans++;
            }
        }

        return ans;
    }
};