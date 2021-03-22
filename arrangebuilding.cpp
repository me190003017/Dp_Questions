#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a=1,b=1,ans,c;
    for(int i=1;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    cout<<pow(a+b,2)<<endl;//number of ways of organizing colonoies when 2 building not conjugatve two side between is road 
    // another way using 2d array
    int ColonoiesB[n+1];
    int ColonoiesS[n+1];
    ColonoiesB[0]=ColonoiesS[0]=0;ColonoiesB[1]=ColonoiesS[1]=1;
    for (size_t i = 2; i <=n; i++)
    {
        ColonoiesS[i]=ColonoiesB[i-1]+ColonoiesS[i-1];
        ColonoiesB[i]=ColonoiesS[i-1];
    }
    cout<<pow(ColonoiesS[n]+ColonoiesB[n],2)<<endl;
}

int main(){
    solve();
    return 0;
}