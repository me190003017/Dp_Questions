#include<bits/stdc++.h>
using namespace std;
// #define int long long 
void solve(){
    string str;
    cin>>str;
    int n=str.size();
    int next[n];
    map<char,int>mp;
    int prev[n];
    for(int i=0;i<n;i++){
        if(mp.find(str[i])!=mp.end()){
            prev[i]=mp[str[i]];
        }else{
            prev[i]=-1;
        }
        mp[str[i]]=i;
    }
    mp.clear();
    for(int i=n-1;i>=0;i--){
        if(mp.find(str[i])!=mp.end()){
            next[i]=mp[str[i]];
        }else{
            next[i]=-1;
        }
        mp[str[i]]=i;
    }
    int dp[n][n];

    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j]=1;
            }
            else if(g==1){
                dp[i][j]=2;
            }else{
                if(str[i]==str[j]){
                    int sn=next[i];
                    int ep=prev[j];
                    if(sn>ep){
                        dp[i][j]=2*dp[i+1][j-1]+2;
                    }else if(sn==ep){
                        dp[i][j]=2*dp[i+1][j-1]+1;
                    }else{
                        dp[i][j]=2*dp[i+1][j-1]-dp[sn+1][ep-1];
                    }
                }else{
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main(){
    solve();
    return 0;
}

