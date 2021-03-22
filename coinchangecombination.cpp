#include<bits/stdc++.h>
using namespace std;
int solve(){
    int arr[]={2,3,5,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum;cin>>sum;
    int dp[sum+1]={0};
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<sum+1;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    return dp[sum];
}
int main(){
    cout<<solve()<<endl;
    return 0;
}