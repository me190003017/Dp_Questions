#include<bits/stdc++.h>
using namespace std;


void solve(){
    string str;
    cin>>str;
    int n=str.size();
    int arr[n];


    int c_sum=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int val=0;
        if(str[i]=='0'){
            val+=1;
        }else if(str[i]=='1'){
            val=-1;
        }
        if(c_sum<0){
            c_sum=val;
        }else{
            c_sum+=val;
        }
        ans=max(ans,c_sum);
    }
    if(ans==0){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

}   
int main(){
    solve();
    return 0; 
}