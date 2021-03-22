#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    int n=str.length();

    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        if(str[i-1]=='0'&&str[i]=='0'){
            dp[i]=0;
        }else if(str[i-1]=='0'&&str[i]!='0'){
            dp[i]=dp[i-1];
        }else if(str[i-1]!='0'&&str[i]=='0'){
            char c=str[i-1];
            if(c=='1'||c=='2'){
                dp[i]=i>=2 ? dp[i-2]:1;
            }else{
                dp[i]=0;
            }
        }else{
            int total=dp[i-1];
            if((str[i-1]=='1')||(str[i-1]=='2'&&str[i]<'7')){
                total+=(i>=2 ? dp[i-2]:1);
            }
            dp[i]=total;
        }
    }
    cout<<dp[n-1]<<endl;
}

int main(){
    solve();
    return 0;
}
