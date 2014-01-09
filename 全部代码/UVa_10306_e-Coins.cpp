#include <iostream>
#include <cstring>
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

const int MAXN = 305;
const int INF = 2139062143;

int f[MAXN][MAXN];

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int m, S, value[2][45];
		cin >> m >> S;
		for (int i = 0; i < m; i++)
			cin >> value[0][i] >> value[1][i];

		memset(f, 0x7f, sizeof(f));
		f[0][0] = 0;
		for (int i = 0; i < m; i++) {
			for (int u = value[0][i]; u <= S; u++) {
				for (int v = value[1][i]; v <= S; v++) {
					f[u][v] = min(f[u][v], f[u - value[0][i]][v - value[1][i]] + 1);
				}
			}
		}

		int ans = INF;
		for (int i = 0; i <= S; ++i) {
			for (int j = 0; j <= S; ++j) {
				if (i*i + j*j == S*S && f[i][j])
					ans = min(ans, f[i][j]);
			}
		}

		if (ans != INF) cout << ans << endl;
		else cout << "not possible" << endl;
	}
	return 0;
}