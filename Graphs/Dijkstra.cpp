#include <bits/stdc++.h>
using namespace std;

void createAdjacencyList(int E, vector<vector<pair<int, int>>> &adj)
{
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
}

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if (curr_dist + wt < dist[adjNode])
            {
                dist[adjNode] = curr_dist + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
// 0 based Indexing
int main()
{
    int V;
    cin >> V;

    vector<vector<pair<int, int>>> adj(V);

    int E;
    cin >> E;

    createAdjacencyList(E, adj);

    vector<int> ans = dijkstra(V, adj);

    for (int i = 0; i < V; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}