#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int l;
    int i;
    int val;
    string psf;
    Pair(int l, int i, int val, string psf)
    {
        this->l = l;
        this->i = i;
        this->val = val;
        this->psf = psf;
    }
};
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[n];
    int omax = INT_MIN;
    int omaxi = 0;
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] > mx)
                {
                    mx = dp[j];
                }
            }
        }
        dp[i] = mx + 1;
        if (omax <= dp[i])
        {
            omax = dp[i];
            omaxi = i;
        }
    }
    cout << omax << endl;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == omax)
        {
            queue<Pair *> q;
            q.push(new Pair(omax, i, arr[i], to_string(arr[i])));
            while (!q.empty())
            {
                Pair *rem = q.front();
                q.pop();
                if (rem->l == 1)
                {
                    // cout<<rem->l<<"\n";
                    cout << rem->psf << endl;
                }
                for (int j = rem->i - 1; j >= 0; j--)
                {
                    if (dp[j] == rem->l - 1 && arr[j] <= rem->val)
                    {
                        // cout<<rem->l<<" ";
                        q.push(new Pair(dp[j], j, arr[j], to_string(arr[j]) + " -> " + rem->psf));
                    }
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
