#include <iostream>
#include <cstring>
using namespace std;

long long dp[30][30][10010];

/* DP(x, c)
   x : previous letter; 
   c : number of letters need to process
   v : rest S
*/
long long DP(int x, int c, int v) {
	if (v < 0 || x > 26 || c > 26 || v > 360) return 0;
	if (dp[x][c][v] != -1) return dp[x][c][v];
	if (c == 0) {
		if (v == 0) {
			return dp[x][c][v] = 1;
		} else {
			return dp[x][c][v] = 0;
		}
	}
	dp[x][c][v] = 0;
	for (int i = x + 1; i <= 26; i++) {
		dp[x][c][v] += DP(i, c - 1, v - i);
	}
	return dp[x][c][v];
}

int main() {
	int L, S, cnt = 0;
	memset(dp, -1, sizeof(dp));
	DP(0, 26, 1000);
	while (cin >> L >> S && (L || S)) {
		cnt++;
		cout << "Case " << cnt << ": " << DP(0, L, S) << endl;
	}
	return 0;
}