#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int c;cin>>c;
    int dp[2][n+1];
    dp[0][2]=c;
    dp[1][2]=c*(c-1);
    for(int i=3;i<=n;i++){
        dp[0][i]=dp[1][i-1];
        dp[1][i]=(c-1)*(dp[1][i-1]+dp[0][i-1]);     
    }
    cout<<dp[0][n]+dp[1][n]<<endl;
}
int main(){
    solve();
    return 0;
}