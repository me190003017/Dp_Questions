#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            int mx=INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];
                int kthval=(i==0?1:arr[i-1])*arr[k]*(j==n-1?1:arr[j+1]);
                mx=max(mx,left+right+kthval);
            }
            dp[i][j]=mx;
        }
    }
    cout<<dp[0][n-1]<<endl;
}
int main()
{
    solve();
    return 0;
}