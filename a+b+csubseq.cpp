#include<bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    cin>>str;
    int a=0;int ab=0;int abc=0;
    for(int i=0;i<str.length();i++){
        char c=str[i];
        if(c=='a'){
            a=2*a+1;
        }else if(c=='b'){
            ab=2*ab+a;
        }else if(c=='c'){
            abc=2*abc+ab;
        }
    } 
    cout<<abc<<endl;
}
int main(){
    solve();
    return 0;
}