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
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    bool dp[n+1][tar+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(i==0&&j==0){
                dp[i][j]=true;
            }else if(j==0){
                dp[i][j]=true;
            }else if(i==0&&j!=0){
                dp[i][j]=false;
            }else{
                if(dp[i-1][j]){
                    dp[i][j]=true;
                }else{
                    int val=arr[i-1];
                    if(val<=j){
                        if(dp[i-1][j-val]){
                            dp[i][j]=true;
                        }else{
                            dp[i][j]=false;
                        }
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
    }
    if(dp[n][tar]){cout<<"true\n";}else{cout<<"false\n";}
    queue<Pair*>q;
    q.push(new Pair("",n,tar));
    while (!q.empty()){
        Pair *rem=q.front();q.pop();
        if(rem->i==0||rem->j==0){
            cout<<rem->psf<<endl;
        }else{

            if(rem->j>=arr[rem->i-1]){
                bool inc=dp[rem->i-1][rem->j-arr[rem->i-1]];
                if(inc){
                    q.push(new Pair(to_string(rem->i-1)+" "+rem->psf,rem->i-1,rem->j-arr[rem->i-1]));
                }
            }
            bool exc=dp[rem->i-1][rem->j];
            if(exc){
                q.push(new Pair(rem->psf,rem->i-1,rem->j));
            }
        }

    }
}

int main(){
    solve();
    return 0;
}