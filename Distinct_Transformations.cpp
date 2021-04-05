#include<bits/stdc++.h>
using namespace std;
// using recursion with memoization (method of dynamic programming )
// int solutionByRecursionApproach(string s,string t,int si,int ti,vector<vector<int>>&dp){
//     if(si==s.length()){
//         if(ti<t.length()){
//             return 0;
//         }else{
//             return 1;
//         }
//     }else if(ti==t.length()){
//         return 1;
//     }

//     char c1=s[si];
//     char c2=t[ti];
//     if(dp[si][ti]!=-1){
//         return dp[si][ti];
//     }

//     int tw=0;
//     if(c1!=c2){
//         tw=solutionByRecursionApproach(s,t,si+1,ti,dp);
//     }else{
//         int tw1=solutionByRecursionApproach(s,t,si+1,ti+1,dp);
//         int tw2=solutionByRecursionApproach(s,t,si+1,ti,dp);
//         tw=tw1+tw2;
//     }
//     dp[si][ti]=tw;
//     return tw;
// }
// using dp with tabulation 
void tabulationDp(string s,string t){
    int m=s.length();
    int n=t.length();
    int dp[n+1][m+1];
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i==n){
                dp[i][j]=1;
            }else if(j==m){
                dp[i][j]=0;
            }else{
                dp[i][j]=dp[i][j+1];
                if(t[i]==s[j]){
                    dp[i][j]+=dp[i+1][j+1];
                }
            }
        }
    }
    cout<<dp[0][0]<<endl;
}
void solve(){
    string str1,str2;
    cin>>str1>>str2;
    // int n=str1.length();
    // int m=str2.length();
    // vector<vector<int>>dp(n,vector<int>(m));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         dp[i][j]=-1;
    //     }
    // }
    // cout<<solutionByRecursionApproach(str1,str2,0,0,dp)<<endl;
    tabulationDp(str1,str2);
}

int main(){
    solve();
    return 0;
}