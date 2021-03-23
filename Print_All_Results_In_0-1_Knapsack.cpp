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
    int n;
    cin>>n;
    int runs[n],balls[n];
    for(int i=0;i<n;i++){
        cin>>runs[i];
    }
    for(int i=0;i<n;i++){
        cin>>balls[i];
    }
    int tballs;cin>>tballs;
    int dp[n+1][tballs+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<tballs+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else {
                int val=balls[i-1];
                if(val<=j){
                    dp[i][j]=max(dp[i-1][j],runs[i-1]+dp[i-1][j-val]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][tballs]<<endl;
    queue<Pair*>q;
    q.push(new Pair("",n,tballs));
    while (!q.empty())
    {
        Pair *rem=q.front();
        q.pop();
        if(rem->j==0||rem->i==0){
            cout<<rem->psf<<endl;
        }else{
            int exc=dp[rem->i-1][rem->j];
            int inc=dp[rem->i-1][rem->j-balls[rem->i-1]]+runs[rem->i-1];
            if(rem->j>=balls[rem->i-1]){
                if(dp[rem->i][rem->j]==inc){
                    q.push(new Pair(to_string(rem->i-1)+" "+rem->psf,rem->i-1,rem->j-balls[rem->i-1]));
                }
            }
            if(dp[rem->i][rem->j]==exc){
                q.push(new Pair(rem->psf,rem->i-1,rem->j));
            }
        }
    }
    
}
int main(){
    solve();
    return 0;
}
// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7