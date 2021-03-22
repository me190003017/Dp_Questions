#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int dp[k+1][n];
    for(int t=0;t<=k;t++){
        for(int d=0;d<n;d++){
            if(t==0||d==0){
                dp[t][d]=0;
            }
            else{
                dp[t][d]=dp[t][d-1];
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
