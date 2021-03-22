#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 0 || k == 0 || n < k)
    {
        cout << 0 << endl;
        return;
    }
    int dp[k + 1][n + 1]={0};
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i > j||i==0||j==0)
            {
                dp[i][j] = 0;
            }
            else if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = i * dp[i][j - 1] + dp[i - 1][j - 1];
                // cout<<dp[i][j]<<endl;
            }
        }
    }
    cout << dp[k][n] << endl;
}
int main()
{
    solve();
    return 0;
}