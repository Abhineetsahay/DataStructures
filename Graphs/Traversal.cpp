#include "Graph.hpp"
#include "./include/Traversal.hpp"

int main() {
    Graph g;
    int V = g.getVertices();
    vector<vector<int>> adj = g.getAdjList();

    Traversal t;

    cout << "\nBFS Traversal: ";
    vector<int> bfsRes = t.bfs(1, V, adj);
    Graph::printGraph(bfsRes);

    cout << "DFS Traversal: ";
    vector<int> dfsRes = t.dfs(1, V, adj);
    Graph::printGraph(dfsRes);

    return 0;
}
