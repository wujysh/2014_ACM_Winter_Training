#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

double dp[15][105];
int n, k;

double DP(int x, int len) {
	if (dp[x][len]) return dp[x][len];
	if (len == 0) return dp[x][len] = 1;
	for (int i = 0; i <= k; i++) {
		if (abs(i - x) <= 1 || x == 10) {
			dp[x][len] += DP(i, len - 1);
		}
	}
	return dp[x][len];
}

int main() {
	while (cin >> k >> n) {
		memset(dp, 0, sizeof(dp));
		DP(10, n);
		cout << setprecision(5) << fixed << (dp[10][n] / pow(k + 1, n)) * 100 << endl;
	}
	return 0;
}