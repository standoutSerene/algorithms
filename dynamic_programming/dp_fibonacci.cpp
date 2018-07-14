#include<iostream>
using namespace std;
int fib(int n){
    if(n==0 || n==1)
        return n;
    return fib(n-1)+fib(n-2);
}

int fibTopDown(int n,int* dp){
    if(n==0 || n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];

}


int fibBottomUp(int n){
    int *dp=new int[n];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n]; 
}

int main(){
    cout<<fib(5)<<endl;

    int dp[100];
    for(int i=0;i<100;i++){
        dp[i]=-1;
    }

    cout<<fibTopDown(5,dp); cout<<endl;
    cout<<fibBottomUp(5); cout<<endl;
    return 0;
}