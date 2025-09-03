#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m)
{
    return row >= 0 && row < n && col >= 0 && col < m;
}
void dfs(int row, int col, string &s, vector<vector<char>> &words, unordered_set<string> &getElements, unordered_set<string> &prefix, vector<vector<bool>> &vis, unordered_set<string> &ans)
{
    if (vis[row][col])
        return;
    vis[row][col] = true;

    s += words[row][col];
    if (prefix.count(s))
    {
        if (getElements.count(s))
            ans.insert(s);

        int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < 8; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (isValid(nr, nc, words.size(), words[0].size()) && !vis[nr][nc])
                dfs(nr, nc, s, words, getElements, prefix, vis, ans);
        }
    }
    s.pop_back();
    vis[row][col] = false;
}

void multiSearch(vector<vector<char>> &words, vector<string> &toFind)
{
    int n = words.size();
    int m = words[0].size();

    unordered_set<string> ans;
    unordered_set<string> prefix;
    unordered_set<string> getElements(toFind.begin(), toFind.end());

    for (auto &w : toFind)
    {
        string pref = "";
        for (char c : w)
        {
            pref += c;
            prefix.insert(pref);
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int j = 0; j < m; j++)
        {
            string s = "";
            dfs(i, j, s, words, getElements, prefix, vis, ans);
        }
    }

    if (ans.empty())
    {
        cout << "No words found!" << endl;
    }
    else
    {
        for (auto &w : ans)
            cout << w << " ";
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> words(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> words[i][j];
        }
    }

    int k;
    cin >> k;

    vector<string> toFind(k);
    for (int i = 0; i < k; i++)
        cin >> toFind[i];

    multiSearch(words, toFind);
}