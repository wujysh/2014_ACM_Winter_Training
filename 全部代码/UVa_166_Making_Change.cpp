#include <iostream>
#include <iomanip>
#include <cstring>
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
const int money[6] = { 5, 10, 20, 50, 100, 200 };
const double eps = 0.005;

int main() {
	int infinite[MAXN], finite[MAXN], m[6];

	memset(infinite, 0x3f, sizeof(infinite));
	infinite[0] = 0;
	for (int i = 0; i < 6; i++) {
		for (int v = money[i]; v < MAXN; v++) {
			infinite[v] = min(infinite[v], infinite[v - money[i]] + 1);
		}
	}

	while (cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4] >> m[5]
		&& (m[0] || m[1] || m[2] || m[3] || m[4] || m[5])) {
		double n;
		cin >> n;

		memset(finite, 0x3f, sizeof(finite));
		finite[0] = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < m[i]; j++) {
				for (int v = MAXN; v >= money[i]; v--) {
					finite[v] = min(finite[v], finite[v - money[i]] + 1);
				}
			}
		}

		int ans = INF;
		int temp = int((n + eps) * 100);// , ans = finite[temp];
		for (int i = temp; i <= 5 * temp; i+=5) {
			int change = i - temp;
			if (infinite[change] + finite[i] < ans) {
				ans = infinite[change] + finite[i];
			}
		}
		
		cout << setw(3) << ans << endl;
	}
	return 0;
}