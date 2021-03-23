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
    int dp[n][m];int ans=INT_MIN;
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){
                dp[i][j]=arr[i][j];
            }else if(i==0){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }else if(i==n-1){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }else{
                dp[i][j]=arr[i][j]+max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
            }
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx=max(mx,dp[i][0]);
    }
    cout<<mx<<endl;
    queue<Pair*>q;
    for(int i=0;i<n;i++){
        if(dp[i][0]==mx){
            q.push(new Pair(to_string(i),i,0));
        }
    }
    while (!q.empty())
    {
        Pair *rem = q.front();
        q.pop();
        if(rem->j==m-1){
            cout<<rem->psf<<endl;
        }else if(rem->i==0){
                int mxv1=max(dp[rem->i][rem->j+1],dp[rem->i+1][rem->j+1]);
                if(dp[rem->i][rem->j+1]==mxv1){
                    q.push(new Pair(rem->psf+" "+"d2",rem->i,rem->j+1));
                }
                if(dp[rem->i+1][rem->j+1]==mxv1){
                    q.push(new Pair(rem->psf+" "+"d3",rem->i+1,rem->j+1));
                }
                // if(dp[rem->i][rem->j+1]==dp[rem->i+1][rem->j+1]){
                //     q.push(new Pair(rem->psf+" "+"d2",rem->i,rem->j+1));
                //     q.push(new Pair(rem->psf+" "+"d3",rem->i+1,rem->j+1));
                // }
        }else if(rem->i==n-1){
                int mxv2=max(dp[rem->i][rem->j+1],dp[rem->i-1][rem->j+1]);
                if(mxv2==dp[rem->i-1][rem->j+1]){
                    q.push(new Pair(rem->psf+" "+"d1",rem->i-1,rem->j+1));
                }                  
                if(dp[rem->i][rem->j+1]==mxv2){
                    q.push(new Pair(rem->psf+" "+"d2",rem->i,rem->j+1));
                }

        }else{
            int mxv3=max(dp[rem->i-1][rem->j+1],max(dp[rem->i][rem->j+1],dp[rem->i+1][rem->j+1]));
            if(dp[rem->i-1][rem->j+1]==mxv3){
                q.push(new Pair(rem->psf+" "+"d1",rem->i-1,rem->j+1));
            }
            if(dp[rem->i][rem->j+1]==mxv3){
                q.push(new Pair(rem->psf+" "+"d2",rem->i,rem->j+1));
            }
            if(dp[rem->i+1][rem->j+1]==mxv3){
                q.push(new Pair(rem->psf+" "+"d3",rem->i+1,rem->j+1));
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
