#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
   
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i+1==n&&j+1==m){
                dp[i][j]=arr[i][j];
            }
            else if(i+1==n){
                dp[i][j]=arr[i][j]+dp[i][j+1];
            }
            else if(j+1==m){
                dp[i][j]=arr[i][j]+dp[i+1][j];
            }
            else{
                dp[i][j]=arr[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][0]<<endl;
}
int main(){
    solve();
    return 0;
}