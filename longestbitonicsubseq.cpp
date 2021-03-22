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
            if(arr[j]<arr[i]){
                if(dp[j]>mx){
                    mx=dp[j];
                }
            }
        }
        dp[i]=mx+1;
         
    }
    int dp2[n];
    for(int i=n-1;i>=0;i--){
        int mx=0;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[i]){
                if(dp2[j]>mx){
                    mx=dp2[j];
                }
            }
        }
        dp2[i]=mx+1;
        dp[i]+=dp2[i];
        ans=max(ans,dp[i]-1);
        
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
