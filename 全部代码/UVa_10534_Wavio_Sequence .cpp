#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x7fffffff;
vector <int> dp, a, front, back;

int main() {
	int n;
	while (cin >> n) {
		a.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		dp.clear();
		dp.push_back(-INF);
		front.resize(n);
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > dp.back()) {
				dp.push_back(a[i]);
				front[i] = dp.size()-1;
			} else {
				vector <int>::iterator it = lower_bound(dp.begin(), dp.end(), a[i]);
				*it = a[i];
				front[i] = it - dp.begin();
			}
		}

		dp.clear();
		dp.push_back(-INF);
		back.resize(n);
		for (int i = a.size()-1; i >= 0; i--) {
			if (a[i] > dp.back()) {
				dp.push_back(a[i]);
				back[i] = dp.size() -1;
			} else {
				vector <int>::iterator it = lower_bound(dp.begin(), dp.end(), a[i]);
				*it = a[i];
				back[i] = it - dp.begin();
			}
		}

		int ans = 1;
		for (int i = 0; i < n; i++) {
			if (min(front[i], back[i]) * 2 - 1 > ans)
				ans = min(front[i], back[i]) * 2 - 1;
		}
		cout << ans << endl;
	}
	return 0;
}