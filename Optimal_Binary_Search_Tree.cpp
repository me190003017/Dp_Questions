#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<< a[i]<<" ";
    // }cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<< b[i]<<" ";
    // }
    // cout<<endl;
    int dp[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = b[i];
            }
            else if (g == 1)
            {
                dp[i][j] = min(b[i] + 2 * b[j], b[j] + 2 * b[i]);
            }
            else
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += b[k];
                }
                // cout<<sum<<endl;
                int mn = INT_MAX;
                for (int k = i; k <= j; k++)
                {
                    int left = k == i ? 0 : dp[i][k - 1];
                    int right = k == j ? 0 : dp[k + 1][j];
                    mn = min(mn, sum + left + right);
                }
                // mn=min(mn,sum+dp[i][j-1]);
                dp[i][j] = mn;
            }
            // cout<<dp[i][j]<<" ";
        }
    }
    cout<< dp[0][n - 1] << endl;
}

int main()
{
    solve();
    return 0;
}