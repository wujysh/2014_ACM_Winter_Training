#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 60010;
bool dp[MAXN];
int w[7], a[MAXN];

int main() {
	int nCase = 0;
	while (cin >> w[1] >> w[2] >> w[3] >> w[4] >> w[5] >> w[6]
			  && (w[1] || w[2] || w[3] || w[4] || w[5] || w[6])) {
		nCase++;

		int sum = 0, cnt = 0, k, x;
		// 
		for (int i = 1; i <= 6; i++) {
			sum += w[i] * i;
			k = 0;
			a[cnt++] = k * i;
			k++;
			x = 0;
			while (x + k < w[i]) {
				a[cnt++] = k * i;
				x += k;
				k = k * 2;
			}
			if (w[i] > x) a[cnt++] = (w[i] - x) * i;
		}
		//
		cout << "Collection #" << nCase << ":" << endl;
		if (sum % 2 != 0) {
			cout << "Can't be divided." << endl;
			cout << endl;
			continue;
		}

		memset(dp, 0, sizeof(dp));
		dp[0] = true;
		for (int i = 0; i < cnt; i++) {
			for (int v = sum / 2; v >= a[i]; v--) {
				if (dp[v - a[i]]) {
					dp[v] = true;
				}
			}
		}

		if (dp[sum / 2]) {
			cout << "Can be divided." << endl;
		} else {
			cout << "Can't be divided." << endl;
		}
		cout << endl;
	}
	return 0;
}