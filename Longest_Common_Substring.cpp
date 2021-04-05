#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1;
    string str2;
    cin>>str1>>str2;
    int n=str1.size();
    int m=str2.size();
    int dp[n+1][m+1];
    int ans=INT_MIN;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0){
                dp[i][j]=0;
            }else if(i==0){
                dp[i][j]=0;
            }else if(j==0){
                dp[i][j]=0;
            }else{
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=0;
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