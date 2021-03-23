#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
        string psf;
        int i;
        int j;
        Pair(string psf,int i,int j){
            this->psf=psf;
            this->i=i;
            this->j=j;
        }
};
void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int dp[n][m];
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1&&j==m-1){
                dp[i][j]=arr[i][j];
            }else if(i==n-1){
                dp[i][j]=arr[i][j]+dp[i][j+1];
            }else if(j==m-1){
                dp[i][j]=arr[i][j]+dp[i+1][j];
            }else{
                dp[i][j]=min(dp[i][j+1],dp[i+1][j])+arr[i][j];
            }
        }
    }
    cout<<dp[0][0]<<endl;
    queue<Pair*>q;
    q.push(new Pair("",0,0));
    while (!q.empty())
    {
        Pair *rem = q.front();
        q.pop();
        if(rem->i==n-1&&rem->j==m-1){
            cout<<rem->psf<<endl;
        }else if(rem->i==n-1){
                q.push(new Pair(rem->psf+"H",rem->i,rem->j+1));
        }else if(rem->j==m-1){
            q.push(new Pair(rem->psf+"V",rem->i+1,rem->j));
        }else{
            if(dp[rem->i][rem->j+1]>dp[rem->i+1][rem->j]){
                q.push(new Pair(rem->psf+"V",rem->i+1,rem->j));
            }else if(dp[rem->i][rem->j+1]<dp[rem->i+1][rem->j]){
                q.push(new Pair(rem->psf+"H",rem->i,rem->j+1));
            }else{
                q.push(new Pair(rem->psf+"V",rem->i+1,rem->j));
                q.push(new Pair(rem->psf+"H",rem->i,rem->j+1));
                
            }
        }
    }
    
}

int main(){
    solve();
    return 0;
}