#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int runs[n],balls[n];
    for(int i=0;i<n;i++){
        cin>>runs[i];
    }
    for(int i=0;i<n;i++){
        cin>>balls[i];
    }
    int tballs;cin>>tballs;
    int dp[n+1][tballs+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<tballs+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else {
                if(j>=balls[i-1]){
                dp[i][j]=max(dp[i-1][j],runs[i-1]+dp[i-1][j-balls[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][tballs]<<endl;
}
int main(){
    solve();
    return 0;
}
// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7