#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int bd=0;
    int sd=0;
    int ans=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            sd++;
        }else{
            ans+=arr[sd]-arr[bd];
            bd=sd=i;
        }
    }
    ans+=arr[sd]-arr[bd];
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
