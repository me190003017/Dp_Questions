#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1;
    string str2;
    cin>>str1>>str2;
    
    int dp[str1.size()+1][str2.size()+1];
    int ans=INT_MIN;
    for(int i=str1.size();i>=0;i--){
        for(int j=str2.size();j>=0;j--){
            if(i==str1.length()||j==str2.length()){
                dp[i][j]=0;
            }else if(str1[i]==str2[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
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