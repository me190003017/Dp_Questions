#include<bits/stdc++.h>
using namespace std;
bool solve(){
    int n;cin>>n;int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;cin>>sum;
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0&&j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }else if(j==0){
                dp[i][j]=true;
            }
            else{
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }else{
                    int val=arr[i-1];
                    if(j>=val){
                        if(dp[i-1][j-val]==true){
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
    }
    return dp[n][sum];

}
int main(){
    cout<<solve()<<endl;
    return 0;
}