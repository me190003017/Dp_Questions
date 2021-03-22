#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int mx=0;
        for(int  j=0;j<i;j++){
            if(arr[j]<=arr[i]){
                if(dp[j]>mx){
                    mx=dp[j];
                }
            }
        }
        dp[i]=mx+arr[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
