#include<iostream>
using namespace std;
int ways(int n){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	int ans = ways(n-1)+ways(n-2)+ways(n-3);
	return ans;
}

int ways2(int n,int k){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	int ans=0;
	for(int i=1;i<=k;i++)
		ans+=ways2(n-i,k);
	return ans;
}

int ways_bottom_up(int n,int k){
	int* dp=new int[n];
	dp[0]=1;
	for(int step=1;step<=n;step++){
		dp[step]=0;
		for(int j=1;j<=k;j++){
			if(step-j>=0)
				dp[step]+=dp[step-j];
		}
	}
	return dp[n];
}
int ways_bottom_up2(int n,int k){
	int* dp2=new int[n];
	dp2[0]=1;
    for(int step=1;step<=k;step++){
		dp2[step]=0;
		for(int j=1;j<=k;j++){
			if(step-j>=0)
				dp2[step]+=dp2[step-j];
		}
	}
	for(int step=k;step<=n;step++){
		dp2[step]=2*dp2[step-1];
        if(step-1-k>=0)
            dp2[step]-=dp2[step-1-k];
	}
	return dp2[n];
}

int main(){
	int n=4;
	cout<<ways(n)<<endl;
	cout<<ways2(3,2)<<endl;
	cout<<ways2(4,3)<<endl;
	cout<<ways2(5,4)<<endl;
	cout<<ways_bottom_up(3,2)<<endl;
	cout<<ways_bottom_up(4,3)<<endl;
	cout<<ways_bottom_up(5,4)<<endl;
    cout<<ways_bottom_up2(3,2)<<endl;
	cout<<ways_bottom_up2(4,3)<<endl;
	cout<<ways_bottom_up2(5,4)<<endl;


    cout<<ways_bottom_up(15,2)<<endl;
	cout<<ways_bottom_up(17,6)<<endl;
	cout<<ways_bottom_up(13,2)<<endl;
    cout<<ways_bottom_up2(15,2)<<endl;
	cout<<ways_bottom_up2(17,6)<<endl;
	cout<<ways_bottom_up2(13,2)<<endl;
}