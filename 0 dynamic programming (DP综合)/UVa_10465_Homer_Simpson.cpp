#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

int main() {
	int m, n, t, f[10010], g[10010], w[2];
	while (cin >> m >> n >> t) {
		w[0] = m;  w[1] = n;
		for (int i = 0; i <= t; i++) {
			f[i] = g[i] = 0;
		}
		for (int i = 0; i < 2; i++) {
			for (int v = w[i]; v <= t; v++) {
				if (g[v - w[i]] + w[i] > g[v]) {
					g[v] = g[v - w[i]] + w[i];
					f[v] = f[v - w[i]] + 1;
				}
				if (g[v - w[i]] + w[i] == g[v]) {
					f[v] = max(f[v], f[v - w[i]] + 1);
				}
			}
		}
		if (g[t] == t) {
			cout << f[t] << endl;
		} else {
			cout << f[t] << " " << t - g[t] << endl;
		}
	}
	return 0;
}