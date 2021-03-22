#include <bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;
int dp[100000];

int MinimumSteps(int n)
{
    if(n==0){
        return 0;
    }
    if(n==1||n==2||n==3){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    cout<<"Hello "<<n<<endl;
    int stp = 1+min(MinimumSteps(n-1),min(MinimumSteps(n-2),MinimumSteps(n-3)));
    dp[n]=stp;
    return stp;
}

int main()
{
    int n;
    cin >> n;
    cout << MinimumSteps(n);
    char c='3';
    if(c>'2'){
        cout<<"c is less than 2"<<endl;
    }else if(c>'5'){
        cout<<"c is greater than 5"<<endl;
    }else{
        cout<<"nothing"<<endl;
    }
    return 0;
}
