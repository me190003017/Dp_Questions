#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    int n=str.size();
    
    int dp[n+1][n+1];
    int ans=INT_MIN;
    for(int i=n;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(i==n||j==n){
                dp[i][j]=0;
            }
            else{
                if((str[i]==str[j])&&(i!=j)){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
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