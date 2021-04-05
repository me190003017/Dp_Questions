#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.size();int m=str2.size();    
    for(int i=0;i<n;i++){
        if(str1[i]==str2[0]){
            break;
        }
    }
    if(i==n){
        cout<<1<<endl;
        return;
    }
    int dp[n+1][m+1];

}

int main(){
    solve();
    return 0;
}