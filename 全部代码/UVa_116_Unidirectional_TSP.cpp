#include <iostream>
#define min(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;
const int INF = 1 << 20;

int main() {
	int a[15][105], f[15][105], suc[15][105], m, n;
	while (cin >> m >> n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				f[i][j] = INF;
			}
			f[i][n - 1] = a[i][n - 1];
		}

		for (int j = n - 2; j >= 0; j--) {
			for (int i = 0; i < m; i++) {
				if (i != 0) {
					if (f[i - 1][j + 1] + a[i][j] < f[i][j]) {
						f[i][j] = f[i - 1][j + 1] + a[i][j];
						suc[i][j] = i - 1;
					} else if (f[i - 1][j + 1] + a[i][j] == f[i][j] && i - 1 < suc[i][j]) {
						suc[i][j] = i - 1;
					}
				} else {
					if (f[m - 1][j + 1] + a[i][j] < f[i][j]) {
						f[i][j] = f[m - 1][j + 1] + a[i][j];
						suc[i][j] = m - 1;
					} else if (f[m - 1][j + 1] + a[i][j] == f[i][j] && m - 1 < suc[i][j]) {
						suc[i][j] = m - 1;
					}
				}
				if (f[i][j + 1] + a[i][j] < f[i][j]) {
					f[i][j] = f[i][j + 1] + a[i][j];
					suc[i][j] = i;
				} else if (f[i][j + 1] + a[i][j] == f[i][j] && i < suc[i][j]) {
					suc[i][j] = i;
				}
				if (i != m - 1) {
					if (f[i + 1][j + 1] + a[i][j] < f[i][j]) {
						f[i][j] = f[i + 1][j + 1] + a[i][j];
						suc[i][j] = i + 1;
					} else if (f[i + 1][j + 1] + a[i][j] == f[i][j] && i + 1 < suc[i][j]) {
						suc[i][j] = i + 1;
					}
				} else {
					if (f[0][j + 1] + a[i][j] < f[i][j]) {
						f[i][j] = f[0][j + 1] + a[i][j];
						suc[i][j] = 0;
					} else if (f[0][j + 1] + a[i][j] == f[i][j] && 0 < suc[i][j]) {
						suc[i][j] = 0;
					}
				}
			}
		}

		int result = INF, mini;
		for (int i = 0; i < m; i++) {
			if (f[i][0] < result) {
				result = f[i][0];
				mini = i;
			}
		}

		int i = mini;
		cout << i + 1;
		for (int j = 0; j < n - 1; j++) {
			cout << " " << suc[i][j] + 1;
			i = suc[i][j];
		}
		cout << endl;
		cout << result << endl;
	}
	return 0;
}