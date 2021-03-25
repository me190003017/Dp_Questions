#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n-1][n-1];
    for(int g=0;g<n-1;g++){
        for(int i=0,j=g;j<n-1;j++,i++){
            if(g==0){
                dp[i][j]=0;
            }else if(g==1){
                dp[i][j]=arr[i]*arr[j]*arr[j+1];
            }else{
                int mn=INT_MAX;
                for(int k=i;k<j;k++){
                    mn=min(mn,dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
                }
                dp[i][j]=mn;
            }
        }
    }
    cout<<dp[0][n-2]<<endl;
}

int main(){
    solve();
    return 0;
}