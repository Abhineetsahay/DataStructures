#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int knapsack(int n, int W, vector<int> &wt, vector<int> &val)
{
    // memorisaion code
    // if (n == 0 || W == 0)
    //     return 0;

    // if (dp[n][W] != -1)
    //     return dp[n][W];

    // if (wt[n - 1] <= W)
    //     dp[n][W] = max(knapsack(n - 1, W, wt, val), val[n - 1] + knapsack(n - 1, W - wt[n - 1], wt, val));
    // else
    //     dp[n][W] = knapsack(n - 1, W, wt, val);

    // return dp[n][W];

    // tabulation code

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < W + 1; j++)
    //     {
    //         if (i == 0 || j == 0)
    //         {
    //             dp[i][j] = 0;
    //             continue;
    //         }

    //         if (wt[i - 1] <= j)
    //         {
    //             dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }
    // return dp[n][W];

    // space optimised code;

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = W; j>= wt[i]; j--)
        {
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    return dp[W];
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // dp.assign(n + 1, vector<int>(W + 1, 0));
    cout << knapsack(n, W, wt, val) << endl;
    return 0;
}
