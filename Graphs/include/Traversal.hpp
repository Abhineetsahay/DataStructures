#include <bits/stdc++.h>
#include "Graph.hpp"

class Traversal
{
private:
    void dfsUtil(int node, vector<int> &result, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        result.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                dfsUtil(neighbor, result, vis, adj);
            }
        }
    }

public:
    vector<int> dfs(int start, int V, vector<vector<int>> &adj)
    {
        vector<int> result;
        vector<int> vis(V + 1, 0);
        dfsUtil(start, result, vis, adj);
        return result;
    }

    vector<int> bfs(int start, int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V + 1, 0);
        vector<int> result;

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node])
            {
                if (!vis[neighbor])
                {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};
