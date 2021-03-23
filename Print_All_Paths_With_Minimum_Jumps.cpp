#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    
    int i;
    int s;
    int j;
    string psf;
    Pair(int i,int s, int j,  string psf)
    {
        this->i = i;
        this->s = s;
        this->j = j;
        this->psf = psf;
    }
};
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            dp[i] = -1;
        }
    }

    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int steps = arr[i];
        int mn = INT_MAX;
        for (int j = 1; j <= steps; j++)
        {
            if (i + j < n)
            {
                if (dp[i + j] != -1)
                {
                    mn = min(mn, dp[i + j]);
                }
            }
        }
        if (mn != INT_MAX)
        {
            dp[i] = 1 + mn;
        }
        else
        {
            dp[i] = -1;
        }
    }
    if (dp[0] != -1)
    {
        cout << dp[0] << endl;
    }
    else
    {
        cout << "NO path available from origin to destination" << endl;
    }
    queue<Pair *> q;
    q.push(new Pair(0, arr[0], dp[0], to_string(0)));
    while (!q.empty())
    {
        Pair *rem = q.front();
        q.pop();
        if (rem->j== 0)
        {
            
            // cout<<rem->l<<"\n";
            cout << rem->psf <<" ."<< endl;
        }
        for (int j = 1;j<=rem->s; j++)
        {
            
            if(rem->i+j<n){
                if (dp[rem->i+j] == rem->j - 1 &&dp[rem->i+j]!=-1)
                {
                // cout<<dp[rem->i+j]<<" ";
                // cout<<rem->l<<" ";
                    q.push(new Pair(rem->i+j, arr[rem->i+j], dp[rem->i+j], rem->psf+ " -> " +to_string(rem->i+j)  ));
                }
            }
        }

    }
}

int main()
{
    solve();
    return 0;
}
// g++ Print_All_Paths_With_Minimum_Jumps.cpp
// ./a.exe
// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0