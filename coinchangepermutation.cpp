#include<bits/stdc++.h>
using namespace std;
int solve(){
    int arr[]={2,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum;cin>>sum;
    int dp[sum+1]={0};
    dp[0]=1;
    for(int i=1;i<sum+1;i++){
        for(int j=0;j<n;j++){
            int coin=arr[j];
            if(i>=coin){
                dp[i]+=dp[i-coin];
            }
        }
    }
    return dp[sum];
}
int main(){
    cout<<solve()<<endl;
    return 0;
}