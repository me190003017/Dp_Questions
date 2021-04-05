#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int dp[n][m];
    int ans=INT_MIN;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(mat[i][j]==0){
                dp[i][j]=0;
            }else if(i==n-1||j==m-1){
                if(mat[i][j]==1){
                    dp[i][j]=1;
                }
            }
            else{
                dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}