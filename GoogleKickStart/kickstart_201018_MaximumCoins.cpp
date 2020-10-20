#include <iostream>
using namespace std;

int map[1001][1001];

int main() {
	int T;
	int tc = 1;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		long long sum[2001] = { 0 };
		long long ans = 0;
		long long tmp;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> tmp;
				sum[i - j+ 1000] += tmp;
			}
		}
		for (int i = 1001-N; i <= 999+N; i++) {
			if (ans < sum[i]) ans = sum[i];
		}
		cout << "Case #" << tc++ << ": " << ans << '\n';
	}
}