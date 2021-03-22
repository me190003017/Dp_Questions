#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1;
    cin>>str1;
    int n=str1.size();
    int dp[n][n];
    int ans=INT_MIN;
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j]=1;
            }else if(g==1){
                dp[i][j]=1;
                if(str1[i]==str1[j]){
                    dp[i][j]=2;
                }
            }else{
                if(str1[i]==str1[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}
int main(){
    solve();
    return 0;
}