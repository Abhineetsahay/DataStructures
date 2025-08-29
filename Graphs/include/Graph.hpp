#include <bits/stdc++.h>
using namespace std;

#ifndef GRAPH_HPP
#define GRAPH_HPP
class Graph
{
private:
    int vertices, edges;
    int typeOfGraph = 0;
    vector<vector<int>> adj;

    void createUndirectedGraph()
    {

        cin >> vertices >> edges;
        adj.resize(vertices + 1);

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void createDirectedGraph()
    {

        cin >> vertices >> edges;
        adj.resize(vertices + 1);

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
    }

public:
    // 0 means Undirected Graph (default value)
    // 1 means Directed Graph
    // 2 means Directed Graph

    Graph(int typeOfGraph = 0)
    {
        cout << "Enter vertices and edges'\n";
        this->typeOfGraph = typeOfGraph;
        if (typeOfGraph)
        {
            createDirectedGraph();
        }
        else
        {
            createUndirectedGraph();
        }
    }

    int getVertices()
    {
        return vertices;
    }

    int getGraphType()
    {
        return this->typeOfGraph;
    }

    vector<vector<int>> getAdjList()
    {
        return adj;
    }

    static void printGraph(const vector<int> &graph)
    {
        for (int node : graph)
        {
            cout << node << ' ';
        }
        cout << '\n';
    }
};
#endif 

