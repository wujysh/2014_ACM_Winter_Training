#include <iostream>
#include <cstring>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

const int MAXN = 100010;
int a[MAXN];
long long dp[MAXN], ans;

int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		ans = dp[0] = a[0];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < n; i++) {
			dp[i] = max(0, dp[i - 1] + a[i]);
			if (dp[i] > ans) ans = dp[i];
		}

		if (ans > 0) {
			cout << "The maximum winning streak is " << ans << "." << endl;
		} else {
			cout << "Losing streak." << endl;
		}
	}
	return 0;
}
