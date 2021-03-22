#include<bits/stdc++.h>
using namespace std;
int dp[1000];
// this one now solved usign memoization
int countPaths(int n){
    if(n==0){
        return 1;
    }else if(n<0){
        return 0;
    }
    if(dp[n]>0){
        return dp[n];
    }
    cout<<"Hello "<<n<<endl;
    int np1=countPaths(n-1);
    int np2=countPaths(n-2);
    int np3=countPaths(n-3);
    int final=np1+np2+np3;
    dp[n]=final;
    return final;
}

// Now lets see how to solve using tabulation
int countPathTab(int n){
    int dp2[n+1];
    dp2[0]=1;
    for(int i=1;i<=n;i++){
        if(i==1){
            dp2[i]=dp2[i-1];
        }
        else if(i==2){  
            dp2[i]=dp2[i-1]+dp2[i-2];
        }else{
            dp2[i]=dp2[i-1]+dp2[i-2]+dp2[i-3];
        }
    }
    return dp[n];
}
int main(){
    int n;cin>>n;
    memset(dp,0,sizeof(dp));
    cout<<countPaths(n)<<endl;
    cout<<countPathTab(n)<<endl;
}