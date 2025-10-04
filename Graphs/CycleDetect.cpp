#include <bits/stdc++.h>
#include "./include/CycleDetect.hpp"

int main()
{
    Graph g(1);
    int V = g.getVertices();
    vector<vector<int>> adj = g.getAdjList();

    CycleDetect Cd;

    if (Cd.isCycle(g.getGraphType(), V, adj))
    {
        cout << "Cycle Detected\n";
    }
    else
    {
        cout << "Not any Cycle Detected\n";
    }
}