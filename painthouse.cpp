#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    int dp[3][n];
    dp[0][0]= arr[0][0];
    dp[1][0] = arr[0][1];
    dp[2][0]=arr[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = arr[i][0]+min(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = arr[i][1]+min(dp[0][i-1],dp[2][i-1]);
        dp[2][i] = arr[i][2]+min(dp[1][i-1],dp[0][i-1]);
        // cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
    }
    
    cout<<min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]))<<endl;
}
int main()
{
    solve();
    return 0;
}