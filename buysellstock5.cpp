#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mpist=INT_MIN;
    int mn=INT_MAX;
    int dpmpisut[n];
    for(int i=0;i<n;i++){
        mn=min(mn,arr[i]);
        mpist=max(mpist,arr[i]-mn);
        dpmpisut[i]=mpist;
    }
    int mx=INT_MIN;
    int mpibt=INT_MIN;
    for(int i=n-1;i>=0;i--){
        mx=max(mx,arr[i]);
        mpibt=max(mpibt,mx-arr[i]);
        dpmpisut[i]+=mpibt;
    }
    cout<<*(max_element(dpmpisut,dpmpisut+n))<<endl;
}

int main(){
    solve();
    return 0;
}
