#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    int prices[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prices[i+1]=arr[i];
    }

    int dp[n+1];
    dp[0]=0;
    dp[1]=prices[1];
    for(int j=2;j<=n;j++){
        dp[j]=prices[j];
        int li=1;
        int ri=j-1;
        while(li<=ri){
            dp[j]=max(dp[li]+dp[ri],dp[j]);
            li++;ri--;
        }

    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
    return 0;
}