#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement (Mid-Semester DAA Question):

    Mr. X is compelled to visit capitals of other countries to explore export opportunities. 
    The world map is represented as an undirected weighted graph where:
        - Each vertex denotes a capital city.
        - Each edge denotes the direct air distance between two capitals.
        - The weight of an edge is the distance (cost).

    Requirement:
    - Find the shortest path from source city (New Delhi → node 0) to a destination city (last node).
    - Use Dijkstra's algorithm to compute shortest paths and maintain a predecessor array.
    - Once the shortest path is obtained, count the number of takeoffs (edges) in that path.

    Weight Loss Rule (per takeoff):
        - On the first takeoff: Mr. X loses 1 kg.
        - On each subsequent takeoff: the loss doubles the previous value.
        - So for k takeoffs, the total loss = 1 + 2 + 4 + ... + 2^(k-1) = (2^k - 1).

    Task:
        1. Compute the shortest path from source (0) to destination (V-1).
        2. Count the number of takeoffs (edges).
        3. Output the total weight loss in kilograms.

    Example:
        Input:
            V = 4, E = 3
            Edges: 
                0 1 5
                1 2 6
                2 3 7
            Initial weight: 100

        Shortest Path: 0 → 1 → 2 → 3
        Takeoffs: 3
        Weight Loss: 2^3 - 1 = 7 kg

    Time Complexity:
        - Best Case: O(log V) (direct connection)
        - Worst Case: O((V + E) log V) (all vertices processed)

*/


void createAdjacencyList(int E, vector<vector<pair<int, int>>> &adj)
{
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
}

int dijkstra(int V, vector<vector<pair<int, int>>> &adj, int weight)
{
    vector<int> dist(V, INT_MAX);
    vector<int> pred(V);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pred[0] = -1;
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
                pred[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    int noOfCountries = 0;
    int j = V - 1;
    while (pred[j] != -1)
    {
        noOfCountries++;
        j = pred[j];
    }
    int oldWeight = weight;
    int i = 1;
    while (noOfCountries != 0)
    {
        weight -= i;
        i = i * 2;
        noOfCountries--;
    }
    return (oldWeight - weight);
}
int main()
{
    int V;
    cin >> V;

    vector<vector<pair<int, int>>> adj(V);

    int E;
    cin >> E;

    createAdjacencyList(E, adj);

    int weight;
    cin >> weight;

    int ans = dijkstra(V, adj, weight);

    cout << ans << ' ';
    cout << '\n';
}