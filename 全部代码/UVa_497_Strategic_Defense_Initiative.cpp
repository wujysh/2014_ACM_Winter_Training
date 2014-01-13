#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

const int MAXN = 100000;
const int INF = 0x3f3f3f3f;
int a[MAXN];
map <int, int> pre;
vector <int> dp;
stack <int> ans;

int main() {
	int nCase;
	cin >> nCase;
	cin.ignore(2);
	while (nCase--) {
		string line;
		int cnt = 0;
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			ss >> a[cnt++];
		}

		pre.clear();
		dp.clear();
		dp.push_back(-INF);

		for (int i = 0; i < cnt; i++) {
			if (a[i] > dp.back()) {
				dp.push_back(a[i]);
				pre[a[i]] = (dp.size() - 2 < 0) ? -1 : dp[dp.size() - 2];
			} else {
				int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
				dp[pos] = a[i];
				pre[a[i]] = (pos - 1 < 0) ? -1 : dp[pos - 1];
			}
		}

		cout << "Max hits: " << dp.size() - 1 << endl;
		int p = dp.back();
		while (p != -INF) {
			ans.push(p);
			p = pre[p];
		}
		while (!ans.empty()) {
			cout << ans.top() << endl;
			ans.pop();
		}

		if (nCase) cout << endl;
	}
	return 0;
}