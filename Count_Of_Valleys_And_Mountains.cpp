#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int val=0;
        for(int j=0;j<i;j++){
            val+=dp[j]*dp[i-1-j];
        }
        dp[i]=val;
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
    return 0;
}