#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.size();

    int dpt[n][n];
    int dpf[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dpt[i][j]=0;
            dpf[i][j]=0;
        }
    }
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            
            if(g==0){
                if(s1[i]=='T'){
                    dpt[i][j]=1;
                    dpf[i][j]=0;
                }else{
                    dpt[i][j]=0;
                    dpf[i][j]=1;   
                }
            }else{
                for(int k=i;k<j;k++){
                    char ope=s2[k];
                    // cout<<ope<<" ";
                    int ltc=dpt[i][k];
                    int rtc=dpt[k+1][j];
                    int lfc=dpf[i][k];
                    int rfc=dpf[k+1][j];
                    if(ope=='&'){
                        // cout<<"&"<<" ";
                        dpt[i][j]+=ltc*rtc;
                        dpf[i][j]+=lfc*rfc+lfc*rtc+ltc*rfc;
                    }else if(ope=='|'){
                        // ope=='|'
                        // cout<<"|"<<" ";
                        dpt[i][j]+=ltc*rtc+ltc*rfc+lfc*rtc;
                        dpf[i][j]+=lfc*rfc;
                    }else{
                        // cout<<"^"<<" ";
                        dpt[i][j]+=ltc*rfc+lfc*rtc;
                        dpf[i][j]+=ltc*rtc+lfc*rfc;
                    }
                }
               
            }
        }
    }
    cout<<dpt[0][n-1]<<endl;
}

int32_t main(){
    solve();
    return 0;
}