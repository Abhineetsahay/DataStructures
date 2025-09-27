#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int climbStairs(int n)
{
    // simple recursion
    // if(n<=2) return n;

    // int ans=climbStairs(n-1)+climbStairs(n-2);
    // return ans;

    // top down approach (memorization)
    // if (n <= 2)
    //     return dp[n] = n;

    // if (dp[n] != -1)
    //     return dp[n];

    // return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);

    // bottom up approach (tabulation)
    // for (int i = 3; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // return dp[n];

    // space optimised code
    int prev = 1;
    int secondPrev = 2;
    int ans = 0;

    for (int i = 3; i <= n; i++)
    {
        ans = prev + secondPrev;
        prev = secondPrev;
        secondPrev = ans;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    dp[1] = 1;
    dp[2] = 2;
    cout << climbStairs(n) << endl;
    return 0;
}