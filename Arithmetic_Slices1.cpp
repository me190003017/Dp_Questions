#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    int ans=0;
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<n;i++){
        if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=0;
        }
        ans+=dp[i];
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}