#include<bits/stdc++.h>
using namespace std;
bool isvalid(int i,int j,int n){
    if(i>=0&&i<n&&j>=0&&j<n){
        return true;
    }else{
        return false;
    }
}
void solve(){
    int n,k,r,c;
    cin>>n;
    cin>>k;
    cin>>r>>c;

    double curr[n][n];
    double next[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            curr[i][j]=0;
            next[i][j]=0;
        }
    }

    curr[r][c]=1;
    for(int m=0;m<k;m++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(curr[i][j]!=0){
                    int ni=0;
                    int nj=0;
                    ni=i-1;nj=j+2;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i+1;nj=j+2;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i-1;nj=j-2;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i+1;nj=j-2;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i+2;nj=j-1;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i+2;nj=j+1;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i-2;nj=j-1;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                    ni=i-2;nj=j+1;if(isvalid(ni,nj,n)){next[ni][nj]+=curr[i][j]/8.0;}
                }
            }
        }
        
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            curr[i][j]=next[i][j];
            next[i][j]=0;
        }
    } 
    }
    double sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=curr[i][j];
        }
    }
    cout << setprecision(17) <<sum<<endl;
}

int main(){
    solve();
    return 0;
}