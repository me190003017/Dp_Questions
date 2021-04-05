#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int m,n;
    cin>>m>>n;
    int P[n];
    int R[n];
    for(int i=0;i<n;i++){
        cin>>P[i];
    }
    for(int j=0;j<n;j++){
        cin>>R[j];
    }
    int T;cin>>T;
    // this is O(n*n) approach;
    // int dp[n];
    // int ans=INT_MIN;
    // dp[0]=R[0];
    // for(int i=1;i<n;i++){
    //     int mx=0;
    //     for(int j=0;j<i;j++){
    //         int dist=P[i]-P[j];
    //         if(dist>T){
    //             mx=max(mx,dp[j]);
    //         }
    //     }
    //     dp[i]=mx+R[i];
    //     ans=max(ans,dp[i]);
    // }
    // cout<<ans<<endl;

    // now this is O(m) approach
    int DP[m+1];
    DP[0]=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[P[i]]=R[i];
    }
    for(int i=1;i<=m;i++){
        if(mp.find(i)==mp.end()){
            DP[i]=DP[i-1];
        }else{
            if(i>T+1){
            DP[i]=max(DP[i-T-1]+0+mp[i],DP[i-1]);
            }else{
               DP[i]=max(mp[i],DP[i-1]); 
            }
        }
    }
    cout<<DP[m]<<endl;
}

int32_t main(){
    solve();
    return 0;
}