#include<bits/stdc++.h>
using namespace std;

int kadans(int arr[],int n){
    int overall_sum=arr[0];
    int current_sum=arr[0];
    for(int i=1;i<n;i++){
        if(current_sum<0){
            current_sum=arr[i];
        }else{
            current_sum+=arr[i];
        }

        if(current_sum>overall_sum){
            overall_sum=current_sum;
        }
        

    }
    return overall_sum;
}
int kadansofTwo(int arr[],int n){
    int newarr[2*n];
    for(int i=0;i<n;i++){
        newarr[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        newarr[n+i]=arr[i];
    } 
    return kadans(newarr,2*n);
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int k;
    cin>>k;
    if(k==1){
        cout<<kadans(arr,n)<<endl;
    }else if(sum<0){
        cout<<kadansofTwo(arr,n)<<endl;
    }else{
        cout<<kadansofTwo(arr,n)+(k-2)*sum<<endl;
    }
}
int main(){
    solve();
    return 0;
}