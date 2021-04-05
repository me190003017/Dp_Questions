#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x;cin>>x;
    map<string ,int>HashMap;
    for(int i=0;i<x;i++){
        string s;
        cin>>s;
        HashMap[s]++;
    }
    string sentence;
    cin>>sentence;
    int n =sentence.size();
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            string W2check=sentence.substr(j,i-j+1);
            // cout<<W2check<<" ";
            if(HashMap.find(W2check)!=HashMap.end()){
                if(j>0){
                dp[i]+=dp[j-1];
                }else{
                    dp[i]+=1;
                }
            }
        }
        // cout<<dp[i]<<" ";
    }
    if(dp[n-1]!=0){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }

}   
int main(){
    solve();
    return 0; 
}