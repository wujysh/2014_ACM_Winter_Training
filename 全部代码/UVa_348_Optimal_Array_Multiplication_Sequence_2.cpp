#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 15;

int path[MAXN][MAXN], r[MAXN], c[MAXN];
long long f[MAXN][MAXN];

void dfs(int x, int y) {
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

		memset(f, 0, sizeof(f));
		memset(path, 0, sizeof(path));

		for (int i = 0; i < n; i++) {
			cin >> r[i] >> c[i];
		}

		for (int len = 1; len < n; len++) {
			for (int i = 0; i + len < n; i++) {
				int j = i + len;
				f[i][j] = INF;
				for (int k = i; k < j; k++) {
					long long sum = f[i][k] + f[k + 1][j] + r[i] * c[j] * c[k];
					if (sum < f[i][j]) {
						f[i][j] = sum;
						path[i][j] = k;
					}
				}
			}
		}

		cout << "Case " << nCase << ": ";
		dfs(0, n - 1);
		cout << endl;
	}
	return 0;
}