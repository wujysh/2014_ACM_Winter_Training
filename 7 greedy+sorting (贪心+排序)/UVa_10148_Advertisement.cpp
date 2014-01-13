#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 10010;

struct node {
	int l, r;
	node(int l1, int r1) {
		l = l1;  r = r1;
	}
	friend bool operator < (node a, node b) {
		return a.r < b.r;
	}
};

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int k, n, left = 0, right = 0;
		vector <node> jogger;
		cin >> k >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);
			if (a < left) left = a;
			if (b > right) right = b;
			jogger.push_back(node(a, b));
		}
		sort(jogger.begin(), jogger.end());

		bool billboard[MAXN * 2];
		memset(billboard, false, sizeof(billboard));

		int ans = 0;
		for (int i = 0; i < jogger.size(); i++) {
			int cnt = 0;
			for (int j = jogger[i].l; j <= jogger[i].r; j++) {
				if (billboard[j + MAXN]) {
					cnt++;
				}
			}
			if (cnt >= k || (jogger[i].r - jogger[i].l < k && cnt - 1 == jogger[i].r - jogger[i].l)) continue;
			for (int j = jogger[i].r; cnt < k && j >= jogger[i].l; j--) {
				if (!billboard[j + MAXN]) {
					billboard[j + MAXN] = true;
					ans++;  cnt++;
				}
			}
		}

		cout << ans << endl;
		for (int i = left; i <= right; i++) {
			if (billboard[i + MAXN]) {
				cout << i << endl;
			}
		}

		if (nCase) cout << endl;
	}
	return 0;
}