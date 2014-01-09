#include <iostream>
#define min(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 15;

int path[MAXN][MAXN];
long long r[MAXN], c[MAXN], dp[MAXN][MAXN];

long long DP(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	path[x][y] = x;
	if (x == y) {
		dp[x][y] = 0;
		return 0;
	}
	dp[x][y] = INF;
	for (int i = x; i < y; i++) {
		long long sum = DP(x, i) + DP(i + 1, y) + r[x] * c[i] * c[y];
		if (sum < dp[x][y]) {
			dp[x][y] = sum;
			path[x][y] = i;
		}
	}
	return dp[x][y];
}

void dfs(int x, int y) {
	if (x > y) return;
	if (x == y) {
		cout << "A" << x + 1;
	} else {
		cout << "(";
		dfs(x, path[x][y]);
		cout << " x ";
		dfs(path[x][y] + 1, y);
		cout << ")";
	}
}

int main() {
	int n, nCase = 0;
	while (cin >> n && n) {
		nCase++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> r[i] >> c[i];
		}

		/*for (int len = 1; len < n; len++) {
			for (int i = 1; i + len <= n; i++) {
			int j = i + len;
			f[i][j] = INF;
			for (int k = i + 1; k <= j; k++) {
			int sum = f[i][k - 1] + f[k][j] + r[i] * c[j] * r[k];
			if (sum < f[i][j]) {
			f[i][j] = sum;
			path[i][j] = k;
			}
			}
			}
			}*/
		DP(0, n - 1);

		cout << "Case " << nCase << ": ";
		dfs(0, n - 1);
		cout << endl;
	}
	return 0;
}
