#include <bits/stdc++.h>
#include "Graph.hpp"

class CycleDetect
{
private:
    bool dfsCheckForDirected(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheckForDirected(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool isCycleDirected(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheckForDirected(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfsCheckForUnDirected(int node, int parentNode, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheckForUnDirected(it, node, adj, vis))
                    return true;
            }
            else if (it != parentNode)
                return true;
        }
        return false;
    }

    bool isCycleUndirected(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);

        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheckForUnDirected(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int type, int V, vector<vector<int>>& adj)
    {
        if (type)
        {
            return isCycleDirected(V, adj);
        }
        else
        {
            return isCycleUndirected(V, adj);
        }
    }
};
