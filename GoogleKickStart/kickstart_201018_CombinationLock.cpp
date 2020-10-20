#include <iostream>
#include <algorithm>
using namespace std;

long long h[100001];
int W;
long long N;
long long psum[100001];

int getl(int i, int l) {
	long long pivot = (h[i] * 2) - N;
	if (pivot - 2 * h[0] <= 0) return -1;
	while (l + 1 < i) {
		if (pivot - 2*h[l + 1] > 0) l++;
		else break;
	}
	return l;
}

int getr(int i, int r) {
	long long pivot = (h[i] * 2) + N;
	while (r < W) {
		if (pivot - 2 * h[r] >= 0) r++;
		else break;
	}
	return r;
}

int main() {
	int T;
	int tc = 1;
	cin >> T;
	while (T--) {
		long long ans = 100000000000001;
		cin >> W >> N;
		for (int i = 0; i < W; i++) cin >> h[i];
		sort(h, h + W);
		psum[0] = h[0];
		for (int i = 1; i < W; i++) {
			psum[i] = psum[i - 1] + h[i];
		}
		int l = -1;
		int r = 0;
		for (int i = 0; i < W; i++) {
			long long now = 0;
			l = getl(i, l);
			r = getr(i, r);
			if (l != -1) {
				now += psum[l] + ((N - h[i])) * (l + 1);
				now += h[i] * (i - l) - psum[i] + psum[l];
			}
			else {
				now += h[i] * (i + 1) - psum[i];
			}
			if (r != W) {
				now += (h[i] + N) * (W - r) - (psum[W - 1] - psum[r - 1]);
				now += psum[r - 1] - psum[i] - h[i] * (r - 1 - i);
			}
			else {
				if (i > 0)now += psum[W - 1] - psum[i] - h[i] * (W - i - 1);
				else now += psum[W - 1] - h[i] * (W - i);
			}
			if (now < ans) ans = now;
		}
		cout << "Case #" << tc++ << ": " << ans << '\n';
	}
}