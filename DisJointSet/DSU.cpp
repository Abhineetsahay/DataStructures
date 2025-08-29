#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
    vector<int> parent, rank, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void UnionByRank(int x, int y)
    {
        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par)
            return;

        if (rank[x_par] < rank[y_par])
        {
            parent[x_par] = y_par;
        }
        else if (rank[x_par] > rank[y_par])
        {
            parent[y_par] = x_par;
        }
        else
        {
            parent[x_par] = y_par;
            rank[x_par]++;
        }
    }
    void UnionBySize(int x, int y)
    {
        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par)
            return;
        if (size[x_par] < size[y_par])
        {
            parent[x_par] = y_par;
            size[y_par] += size[x_par];
        }
        else
        {
            parent[y_par] = x_par;
            size[x_par] += size[y_par];
        }
    }
};

// 0 based indexing
int main()
{
    DSU d1(7);

    d1.UnionBySize(0, 1);
    d1.UnionBySize(1, 2);
    d1.UnionBySize(3, 5);
    d1.UnionBySize(5, 3);
    d1.UnionBySize(4, 5);
    if (d1.find(2) == d1.find(6))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    d1.UnionBySize(0, 6);
    if (d1.find(2) == d1.find(6))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    return 0;
}