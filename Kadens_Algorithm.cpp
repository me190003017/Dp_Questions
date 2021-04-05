#include<bits/stdc++.h>
using namespace std;

void kadans(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
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
    cout<<overall_sum<<endl;
}

int main(){
    kadans();
    return 0;
}