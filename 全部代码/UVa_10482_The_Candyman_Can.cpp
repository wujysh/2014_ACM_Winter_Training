#include <iostream>
#include <cstring>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

const int MAXN = 650;
const int INF = 0x3f3f3f3f;
bool dp[MAXN][MAXN];

int main() {
	int nCase, cnt = 0;
	cin >> nCase;
	while (nCase--) {
		cnt++;
		int n, w[40], sum = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
			sum += w[i];
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0] = true;
		for (int i = 1; i <= n; i++) {
			for (int u = sum; u >= 0; u--) {
				for (int v = sum; v >= 0; v--) {
					if (dp[u][v]) {
						dp[u + w[i]][v] = true;
						dp[u][v + w[i]] = true;
					}
				}
			}
		}

		int ans = INF;
		for (int u = 0; u <= sum; u++) {
			for (int v = 0; v <= sum; v++) {
				if (dp[u][v]) {
					int w = sum - u - v;
					ans = min(ans, max(max(u, v), w) - min(min(u, v), w));
				}
			}
		}

		cout << "Case " << cnt << ": " << ans << endl;
	}
	return 0;
}