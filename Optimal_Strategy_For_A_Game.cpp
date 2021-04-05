#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j]=arr[i];
            }else if(g==1){ 
                dp[i][j]=max(arr[i],arr[j]);
            }else{
                int part1=arr[i]+min(dp[i+1][j-1],dp[i+2][j]);
                int part2=arr[j]+min(dp[i+1][j-1],dp[i][j-2]);
                dp[i][j]=max(part1,part2);            
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main(){
    solve();
    return 0;
}