#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    cin >> n;
    int runs[n], balls[n];
    for (int i = 0; i < n; i++)
    {
        cin >> runs[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> balls[i];
    }
    int tballs;
    cin >> tballs;
    int dp[tballs + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = balls[i]; j < tballs + 1; j++)
        {
            int newtotal;
            newtotal=runs[i]+dp[j-balls[i]];
            dp[j]=max(dp[j],newtotal);
        }
    }
    return dp[tballs];
}
int main()
{
    cout << solve() << endl;
    return 0;
}