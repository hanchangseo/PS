#include <iostream>
#include <vector>
#include <string>
using namespace std;

string input;

int main() {
	int T;
	int tc = 1;
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> input;
		int SIZE = input.size();
		int kickcnt = 0;
		for (int i = 0; i < SIZE; i++) {
			if (input[i] == 'K') {
				if (i + 3 < SIZE && input[i + 1] == 'I' && input[i + 2] == 'C' && input[i + 3] == 'K') {
					kickcnt++;
				}
			}
			else if (input[i] == 'S') {
				if (i + 4 < SIZE && input[i + 1] == 'T' && input[i + 2] == 'A' && input[i + 3] == 'R' && input[i + 4] == 'T') {
					ans += kickcnt;
				}
			}
		}
		cout << "Case #" << tc++ << ": " << ans << '\n';
	}
}