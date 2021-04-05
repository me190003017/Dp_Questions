#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    int n=str1.size();
    int m=str2.size();
    int x,y;
    cin>>x>>y;
    int dp[n+1][m+1];
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i==n&&j==m){
                dp[i][j]=0;
            }else if(i==n){
                dp[i][j]=dp[i][j+1]+(y);
            }else if(j==m){
                dp[i][j]=dp[i+1][j]+(x);
            }else{
                if(str1[i]==str2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    dp[i][j]=min((x)+dp[i+1][j],(y)+dp[i][j+1]);
                }
            }
        }
    }
    cout<<dp[0][0]<<endl;
}

int main(){
    solve();
    return 0;
}