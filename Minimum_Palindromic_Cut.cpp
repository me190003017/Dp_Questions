#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    int n=str.size();
    bool dp1[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp1[i][j]=true;
            }else if(g==1){
                dp1[i][j]=str[i]==str[j];
            }else{
                dp1[i][j]=false;
                if(str[i]==str[j]){
                    dp1[i][j]=dp1[i+1][j-1];
                }
            }
        }
    }
    // one way n*n*n time complexicity
    int dp2[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp2[i][j]=0;
            }else if(g==1){
                if(str[i]==str[j]){
                    dp2[i][j]=0;
                }else{
                    dp2[i][j]=1;
                }
            }else{
                if(dp1[i][j]){
                    dp2[i][j]=0;
                }else{
                    int mn=INT_MAX;
                    for(int k=i;k<=j-1;k++){
                        mn=min(dp2[i][k]+dp2[k+1][j]+1,mn);
                    }
                    dp2[i][j]=mn;
                }
            }
        }
    }
    cout<<dp2[0][n-1]<<endl;
    // 2nd way n*n complexicity
    int dp3[n];
    dp3[0]=0;
    for(int j=1;j<n;j++){
        if(dp1[0][j]){
            dp3[j]=0;
        }else{
            int mn=INT_MAX;
            for(int i=j;i>=1;i--){
                if(dp1[i][j]){
                    mn=min(dp3[i-1],mn);
                }
            }
            dp3[j]=mn+1;
        }
    }
    cout<<dp3[n-1]<<endl;;

}

int main(){
    solve();
    return 0;
}