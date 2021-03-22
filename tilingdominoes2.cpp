#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int m;cin>>m;//m*1 ki tiles h; m*n ka floor
    int dp[n+1];
    for(int i=1;i<m;i++){
        dp[i]=1;
    }
    dp[m]=2;
    for(int i=m+1;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-m];
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
    return 0;
}