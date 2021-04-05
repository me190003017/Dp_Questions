#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int maxSum[n];
    int ans=INT_MIN;
    int overall_sum=arr[0];
    int current_sum=arr[0];
    maxSum[0]=current_sum;
    for(int i=1;i<n;i++){
        if(current_sum<0){
            current_sum=arr[i];
        }else{
            current_sum+=arr[i];
        }
        maxSum[i]=current_sum;
    }
    int exactk=0;//sum of first window
    for(int i=0;i<k;i++){
        exactk+=arr[i];
    }
    ans=max(ans,exactk);
    for(int i=k;i<n;i++){
        exactk+=arr[i]-arr[i-k];
        ans=max(exactk,ans);
        int morek=maxSum[i-k]+exactk;
        ans=max(morek,ans);
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}