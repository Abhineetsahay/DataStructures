#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int vertices, edges;
    vector<vector<int>> adj;

    void createGraph() {
        cin >> vertices >> edges;
        adj.resize(vertices + 1);  
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
    }

    void dfsUtil(int node, vector<int>& result, vector<int>& vis) {
        vis[node] = 1;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfsUtil(neighbor, result, vis);
            }
        }
    }

public:
    Graph() {
        createGraph();
    }

    vector<int> bfs(int start) {
        vector<int> vis(vertices + 1, 0);
        vector<int> result;

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }

    vector<int> dfs(int start) {
        vector<int> result;
        vector<int> vis(vertices + 1, 0);
        dfsUtil(start, result, vis);
        return result;
    }

    static void printGraph(const vector<int>& graph) {
        for (int node : graph) {
            cout << node << ' ';
        }
        cout << '\n';
    }
};

int main() {
    Graph g;

    vector<int> bfsResult = g.bfs(1);
    cout << "BFS Traversal: ";
    g.printGraph(bfsResult);

    vector<int> dfsResult = g.dfs(1);
    cout << "DFS Traversal: ";
    g.printGraph(dfsResult);
}
