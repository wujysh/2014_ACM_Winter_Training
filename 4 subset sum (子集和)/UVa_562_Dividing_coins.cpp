#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int n, sum = 0, coin[110];
		bool dp[50010];

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
			sum += coin[i];
		}

		memset(dp, false, sizeof(dp));
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			for (int v = sum; v >= coin[i]; v--) {
				if (dp[v - coin[i]]) {
					dp[v] = true;
				}
			}
		}

		for (int v = sum / 2; v >= 0; v--) {
			if (dp[v]) {
				cout << sum - 2 * v << endl;
				break;
			}
		}
	}
	return 0;
}