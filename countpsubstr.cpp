#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1;
    cin>>str1;
    int n=str1.size();
    bool dp[n][n];
    int ans=0;
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j]=true;
            }else if(g==1){
                dp[i][j]=false;
                if(str1[i]==str1[j]){
                    dp[i][j]=true;
                }
            }else{
                if(str1[i]==str1[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=false;
                }
            }
            if(dp[i][j]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}