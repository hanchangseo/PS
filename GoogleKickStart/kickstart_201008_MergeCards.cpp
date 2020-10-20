#include <iostream>
using namespace std;

double dp[5001][5001];

void getdp() {
	dp[1][1] = 0;
	for (int n = 2; n <= 5000; n++) {
		dp[n][1] = dp[n-1][1] + 1/((double)n-1);
		dp[n][n] = dp[n][1];
		for (int j = 2; j < n; j++) {
			dp[n][j] = (dp[n-1][j-1]*(j-2) + dp[n-1][j]*(n-j-1)+ dp[n-1][j-1]+dp[n-1][j]+2)/(n-1);
		}
	}
}

int main() {
	int T;
	int tc = 1;
	cin >> T;
	getdp();
	while (T--) {
		double ans = 0;
		int N;
		cin >> N;
		double input;
		for (int i = 1; i <= N; i++) {
			cin >> input;
			ans += (dp[N][i]*input);
		}
		printf("Case #%d: %.9f\n", tc++ , ans);
	}
}