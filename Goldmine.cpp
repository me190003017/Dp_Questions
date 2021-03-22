#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n-1; i >= 0; i--)
        {
            if (j + 1 == m)
            {
                dp[i][j] = arr[i][j];
            }
            else if(i+1==n){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }
            else if(i==0){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }
            else{
                dp[i][j]=arr[i][j]+max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
            }
        }
    }
    int mn=INT_MIN;
    for(int j=0;j<m;j++){
        mn=max(mn,dp[j][0]);
    }
    cout<<mn<<endl;
}
int main()
{
    solve();
    return 0;
}