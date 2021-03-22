#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int fee;cin>>fee;
    int obsp=-arr[0];
    int ossp=0;
    for(int i=1;i<n;i++){
        int nbsp=0;
        int nssp=0;
        if(ossp-arr[i]>obsp){
            nbsp=ossp-arr[i];
        }else{
            nbsp=obsp;
        }
        if(obsp+arr[i]-fee>ossp){
            nssp=obsp+arr[i]-fee;
        }else{
            nssp=ossp;
        }
        obsp=nbsp;
        ossp=nssp;
    }
    cout<<ossp<<endl;
}
int main(){
    solve();
    return 0;
}