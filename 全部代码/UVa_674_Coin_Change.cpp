#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 7500;
const int money[5] = { 1, 5, 10, 25, 50 };
long long dp[MAXN];

long long dp[MAXN][5];
long long DP(int v, int x) {
	if (dp[v][x] != 0) return dp[v][x];
	if (v == 0) return dp[v][x] = 1;
	for (int i = x; i < 5; i++) {
		if (v >= money[i]) {
			dp[v][x] += DP(v - money[i], i);
		}
	}
	return dp[v][x];
}

int main() {
	int n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < 5; i++) {
		for (int v = money[i]; v < MAXN; v++) {
			dp[v] += dp[v - money[i]];
		}
	}
	while (cin >> n) {
		cout << dp[n] << endl;
	}
	return 0;
}