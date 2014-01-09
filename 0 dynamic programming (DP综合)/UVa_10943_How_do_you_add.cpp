#include <iostream>
#include <cstring>
using namespace std;

long long dp[110][110];
int n, k;

long long DP(int x, int step) {
	if (dp[x][step]) return dp[x][step];
	if (step == 1) return dp[x][step] = 1;
	for (int i = 0; i <= x; i++) {
		dp[x][step] += DP(x - i, step - 1);
		dp[x][step] %= 1000000;
	}
	return dp[x][step];
}

int main() {
	memset(dp, 0, sizeof(dp));
	while (cin >> n >> k && (n || k)) {
		DP(n, k);
		cout << dp[n][k] << endl;
	}
	return 0;
}