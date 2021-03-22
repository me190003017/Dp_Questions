#include<bits/stdc++.h>
using namespace std;

int visited[1000];
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    if(visited[n]!=-1){
        // cout<<visited[n]<<endl;
        return visited[n];
    }
    cout<<"Hello - > "<<n<<endl;
    int fibn1=fib(n-1);
    int fibn2=fib(n-2);
    int fib=fibn1+fibn2;
    // cout<<fibn1<<" "<<fibn2<<endl;
    visited[n]=fib;
    return fib;
}


int main(){
    int n;
    cin>>n;
    memset(visited,-1,sizeof(visited));
    cout<<fib(n)<<endl;
    getchar();
    return 0;
}