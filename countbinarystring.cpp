#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a=1,b=1,ans,c;
    for(int i=1;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    cout<<a+b<<endl;//number of binary string of lenth n donot contain conjugate zero
    // another way using 2d array
    int dp0[n+1];
    int dp1[n+1];
    dp0[0]=dp1[0]=0;dp0[1]=dp1[1]=1;
    for (size_t i = 2; i <=n; i++)
    {
        dp1[i]=dp0[i-1]+dp1[i-1];
        dp0[i]=dp1[i-1];
    }
    cout<<dp1[n]+dp0[n]<<endl;
}

int main(){
    solve();
    return 0;
}