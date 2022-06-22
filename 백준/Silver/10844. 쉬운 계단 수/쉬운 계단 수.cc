#include <iostream>
using namespace std;

const int sz=101;
int N;
int dp[sz][11];
long long int moder=1e9;

long long int f(int n, int num){
	if(n==1)	return 1;
	if(dp[n][num]) return dp[n][num];
	//prevent number from being off-limit
	if(num==1)
	    return dp[n][num]= f(n-1,num+1)%moder;
	if(num==10)
	    return dp[n][num]= f(n-1,num-1)%moder;	
	return dp[n][num] = f(n-1, num-1)%moder +f(n-1,num+1) %moder;
}
long long cnt=0;
int main(int argc, char *argv[])
{
	cin >> N;
	
	for(int i=1;i<=9;i++)
	    cnt = (cnt + f(N,i))%moder;
	cout << cnt << endl;
}