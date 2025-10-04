#include <bits/stdc++.h>
using namespace std;

int createAdjacencyList(int E, vector<vector<pair<int, int>>> &adj)
{
    int maxWt = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        maxWt = max(maxWt, wt);
    }
    return maxWt;
}

bool dijkstra(int V, int &speed, vector<vector<pair<int, int>>> &adj)
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
            if (wt <= speed && curr_dist + wt < dist[adjNode])
            {
                dist[adjNode] = curr_dist + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist[V - 1] != INT_MAX;
}

// 0 based Indexing
int main()
{
    int V;
    cin >> V;

    vector<vector<pair<int, int>>> adj(V);

    int E;
    cin >> E;

    int maxSpeed = createAdjacencyList(E, adj);

    int start = 1, end = maxSpeed;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (dijkstra(V, mid, adj))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << ans << '\n';
}