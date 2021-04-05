#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int dp[n+1][10];
    map<int,vector<int>>mp;
    mp[0]={0,8};
    mp[1]={1,2,4};
    mp[2]={1,2,3,5};
    mp[3]={2,3,6};
    mp[4]={1,4,5,7};
    mp[5]={2,4,5,6,8};
    mp[6]={3,5,6,9};
    mp[7]={4,7,8};
    mp[8]={5,7,8,9,0};
    mp[9]={6,9,8};
    int ans;
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=0;j<10;j++){
            if(i==1){
                dp[i][j]=1;
            }else{
                int sum=0;
                for(auto it:mp[j]){
                    int x=it;
                    sum+=dp[i-1][x];
                }
                dp[i][j]=sum;
            }
            ans+=dp[i][j];
        }
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}