#include <iostream>
using namespace std;
int dp[100];
int fibo(int n) {
	if (n == 0) return n; 
	if (n == 1) return n;
	if (dp[n] != 0) {
		return dp[n];
	}
	else {
		dp[n] = fibo(n - 1) + fibo(n - 2);
		return dp[n];
	}
	
}
int main() {
	for (int i = 1; i <= 10; i++) {
		cout<<fibo(i)<<endl;
	}
}