#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1,pattern;
    cin>>str1>>pattern;
    int m=str1.size();
    int n=pattern.size();

    bool dp[n+1][m+1];
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i==n&&j==m){
                dp[i][j]=true;
            }else if(i==n){
                dp[i][j]=false;
            }else if(j==m){
                dp[i][j]=false;
                if(pattern[i]=='*'){
                    dp[i][j]=dp[i+1][j];
                }
            }else if(pattern[i]=='*'){
                dp[i][j]=dp[i+1][j]||dp[i][j+1];
            }else if(pattern[i]=='?'){
                dp[i][j]=dp[i+1][j+1];
            }else if(pattern[i]==str1[j]){
                dp[i][j]=dp[i+1][j+1];
            }else{
                dp[i][j]=false;
            }
        }
    }
    if(dp[0][0]){
    cout<<"true"<<endl;
    }else{
        cout<<"false\n";
    }
}
int main(){
    solve();
    return 0;
}