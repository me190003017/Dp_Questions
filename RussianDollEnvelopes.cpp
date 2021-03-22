#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    sort(arr.begin(),arr.end());

    // cout<<"\n\n";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].first<<" ";
    //     cout<<arr[i].second<<"\n";
    // }
    // cout<<endl;
    int dp[n];
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int mx=0;
        for(int j=0;j<i;j++){
            if((arr[j].second<arr[i].second)&&(arr[j].first<arr[i].first)){
                mx=max(mx,dp[j]);
            }
        }
        dp[i]=mx+1;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

}

int main(){
    solve();
    return 0;
}
