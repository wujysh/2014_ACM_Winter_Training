#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 30010;
const int money[5] = { 1, 5, 10, 25, 50 };
long long dp[MAXN];

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
		if (dp[n] > 1) {
			cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
		} else {
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
	}
	return 0;
}