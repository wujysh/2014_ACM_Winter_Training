#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int l, r;
	node(int l1, int r1) {
		l = l1;  r = r1;
	}
	friend bool operator < (const node a, const node b) {
		return a.l < b.l;
	}
};

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int m, l, r;
		vector <node> line, ans;
		cin >> m;
		while (cin >> l >> r && (l || r)) {
			if (l < m && r > 0) {
				line.push_back(node(l, r));
			}
		}
		sort(line.begin(), line.end());

		if (line.empty() || line[0].l > 0) {
			cout << 0 << endl;
		} else {
			int cur = 0;
			bool flag = false;

			for (int i = 0; i < line.size(); i++) {
				if (line[i].l <= cur) {
					if (ans.empty()) {
						ans.push_back(line[i]);
					} else if (line[i].r > ans.back().r) {
						ans.back() = line[i];
					}
				} else {
					cur = ans.back().r;
					ans.push_back(line[i]);
				}
				if (ans.back().r >= m) {
					flag = true;
					break;
				}
			}

			if (flag) {
				cout << ans.size() << endl;
				for (int i = 0; i < ans.size(); i++) {
					cout << ans[i].l << " " << ans[i].r << endl;
				}
			} else {
				cout << 0 << endl;
			}
		}
		if (nCase) cout << endl;
	}
	return 0;
}