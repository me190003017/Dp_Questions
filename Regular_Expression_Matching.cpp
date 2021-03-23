#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;cin>>str;
    string pattern;cin>>pattern;
    int n=pattern.size();
    int m=str.size();
    bool dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0){
                dp[i][j]=true;
            }else if(i==0){
                dp[i][j]=false;
            }else if(j==0){
                dp[i][j]=false;
                if(pattern[i-1]=='*'){
                    dp[i][j]=dp[i-2][j];
                }
            }else if(pattern[i-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }else if(pattern[i-1]==str[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else if (pattern[i-1]=='*'){
                dp[i][j]=dp[i-2][j];
                if(pattern[i-2]==str[j-1]||pattern[i-2]=='.'){
                    dp[i][j]=dp[i][j-1]||dp[i-2][j];
                }
            }
            
        }
    }
    if(dp[n][m]){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }
}

int main(){
    solve();
    return 0;
}