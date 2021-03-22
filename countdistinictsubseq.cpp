#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    string str;
    cin>>str;
    int n=str.size();
    int dp[n+1];
    dp[0]=1;
    map<char,int>mp;
    for(int i=1;i<n+1;i++){
        dp[i]=2*dp[i-1];
        if(mp.find((str[i-1]))!=mp.end()){
            int j=mp[str[i-1]];
            dp[i]-=dp[j-1];
        }
        mp[str[i-1]]=i;
        
    }
    cout<<dp[n]-1<<endl;
}

int32_t main(){
    solve();
    return 0;
}