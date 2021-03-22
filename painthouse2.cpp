#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<vector<int>> arr(n, vector<int>(c));
    int dp[n][c];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int least = INT_MAX;
    int sleast = INT_MAX;
    for (int j = 0; j < c; j++)
    {
        dp[0][j] = arr[0][j];
        if (dp[0][j] <= least)
        {
            sleast = least;
            least = dp[0][j];
        }
        else if (dp[0][j] <= sleast)
        {
            sleast = dp[0][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
            int newleast = INT_MAX;
            int newsleast = INT_MAX;
        for (int j = 0; j < c; j++)
        {
            if (least == dp[i - 1][j])
            {
                dp[i][j] = arr[i][j] + sleast;
            }
            else
            {
                dp[i][j] = arr[i][j] + least;
            }

            
            if (dp[i][j] <= newleast)
            {
                newsleast = least;
                newleast = dp[i][j];
            }
            else if (dp[i][j] <= sleast)
            {
                newsleast = dp[i][j];
            }
            
        }
        least=newleast;
        sleast=newsleast;
    }
    int mn = INT_MAX;
    for (int j = 0; j < c; j++)
    {
        // cout << dp[n - 1][j] << " ";
        mn = min(dp[n - 1][j], mn);
    }
    cout << endl;
    cout << mn << endl;
}
int main()
{
    solve();
    return 0;
}
// 4
// 1 5 7
// 5 8 4
// 3 2 9
// 1 2 4