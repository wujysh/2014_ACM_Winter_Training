#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
vector <int> dp, a;

int main() {
	int cnt = 0, x;
	while (cin >> x && x != -1) {
		cnt++;
		if (cnt > 1) cout << endl;

		a.clear();
		a.push_back(x);
		while (cin >> x && x != -1)
			a.push_back(x);
		reverse(a.begin(), a.end());

		dp.clear();
		dp.push_back(-INF);
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > dp.back()) {
				dp.push_back(a[i]);
			} else {
				int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
				dp[pos] = a[i];
			}
		}

		cout << "Test #" << cnt << ":" << endl;
		cout << "  maximum possible interceptions: " << dp.size() - 1 << endl;
	}
	return 0;
}