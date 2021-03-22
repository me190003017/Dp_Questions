#include <bits/stdc++.h>
using namespace std;

int MinimumSteps(int n)
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[n + 1]={1000000};
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            int mn = INT_MAX;
            for (int j = 0; j <= arr[i]; j++)
            {
                if (dp[i + j] != 1000000 && (i + j) <= n)
                {
                    mn = min(dp[i + j], mn);
                }
            }
            if (mn != INT_MAX)
            {
                mn += 1;
                dp[i] = mn;
            }
        }
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    cout << MinimumSteps(n);
    return 0;
}
