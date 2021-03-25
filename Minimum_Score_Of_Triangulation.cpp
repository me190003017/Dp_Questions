#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j]=0;
            }else if(g==1){
                dp[i][j]=0;
            }else if(g==2){
                dp[i][j]=arr[i]*arr[i+1]*arr[j];
                // or you can write dp[i][j]=arr[i]*arr[i+1]*arr[i+2]; because g=j-i =>j=g+i
            }else{
                int mn=INT_MAX;
                for(int k=i+1;k<j;k++){
                    int itria=arr[i]*arr[j]*arr[k];
                    int partl=dp[i][k];
                    int partr=dp[k][j];
                    mn=min(itria+partl+partr,mn);
                }
                dp[i][j]=mn;
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
int main(){
    solve();
    return 0;
}
