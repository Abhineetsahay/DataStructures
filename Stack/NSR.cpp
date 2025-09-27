#include <bits/stdc++.h>
using namespace std;

//Next Smallest Right
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ((i + 1 == n) ? '\n' : ' ');
    }

    return 0;
}
