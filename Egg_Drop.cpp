#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n;cin>>k;
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i==1){
                dp[i][j]=j;
            }else if(j==0||i==0){
                dp[i][j]=0;
            }else if(j==1){
                dp[i][j]=1;
            }else{
                int ans=INT_MAX;
                for(int mj=j-1,pj=0;mj>=0;mj--,pj++){
                    ans=min(ans,max(dp[i-1][pj],dp[i][mj]));
                }
                dp[i][j]=ans+1;
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
int main(){
    solve();
    return 0;
}