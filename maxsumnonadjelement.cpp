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
    int dp[2][n];
    dp[0][0]= arr[0];
    dp[1][0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = arr[i]+dp[1][i-1];
        dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
        // cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
    }
    
    cout<<max(dp[0][n-1],dp[1][n-1])<<endl;
}
int main()
{
    solve();
    return 0;
}