#include <bits/stdc++.h>
using namespace std;

// Now lets see how to solve using tabulation
int countPathTab(int n)
{   int dp[n + 1];
    dp[n] = 1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i]=0;
    }


    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            if(i + j <=n){
                dp[i]+=dp[i+j];
            }
            
        }
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    return dp[0];
}
int main()
{
    int n;
    cin >> n;

    cout << countPathTab(n) << endl;
}