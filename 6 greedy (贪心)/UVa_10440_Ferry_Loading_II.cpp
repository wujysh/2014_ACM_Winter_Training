#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2000;

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int n, t, m, time[MAXN];
		cin >> n >> t >> m;
		for (int i = 0; i < m; i++) {
			cin >> time[i];
		}
		sort(time, time + m);
		bool first = m % n;
		int arrived = 0, times = 0, trips = 0;
		for (int i = 0; i < m; i++) {
			if (times < time[i]) {
				times = time[i];
			}
			arrived++;
			if (!first) {
				if (arrived == n) {
					trips++;
					times += 2 * t;
					arrived = 0;
				}
			} else if (arrived == m % n) {
				first = false;
				trips++;
				times += 2 * t;
				arrived = 0;
			}
		}
		cout << times - t << " " << trips << endl;
	}
	return 0;
}