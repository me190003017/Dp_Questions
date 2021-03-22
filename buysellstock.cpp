#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=INT_MIN;
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        mn=min(mn,arr[i]);
        ans=max(ans,arr[i]-mn);
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
