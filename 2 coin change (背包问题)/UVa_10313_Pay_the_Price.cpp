#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 310;
long long dp[MAXN][MAXN];

int main() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i <= 300; i++) dp[0][i] = 1;
	for (int i = 1; i <= 300; i++) {
		for (int v = 1; v <= 300; v++) {
			if (v >= i) dp[v][i] = dp[v][i - 1] + dp[v - i][i];
			else dp[v][i] = dp[v][i - 1];
		}
	}

	char line[255];
	while (gets(line) != NULL) {
		int s, l1, l2;
		int cnt = sscanf(line, "%d%d%d", &s, &l1, &l2);

		if (l1 > 300) l1 = 300;
		if (l2 > 300) l2 = 300;
		if (cnt == 1) {
			l2 = 300;
			l1 = 0;
		}
		if (cnt == 2) {
			l2 = l1;
			l1 = 0;
		}
		if (l1 < 0) l1 = 0;
		if (l2 < 0) l2 = 0;

		if (s == 0 && l1 == 0) cout << 1 << endl;
		else cout << dp[s][l2] - dp[s][l1 - 1] << endl;
	}
	return 0;
}