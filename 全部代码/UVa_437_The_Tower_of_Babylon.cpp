#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200;

struct node {
	int a, b, s, h;
	friend bool operator<(const node a, const node b) {
		return a.s > b.s;
	}
	node(int a1, int b1, int h1) {
		a = a1; b = b1; s = a1 * b1; h = h1;
	}
};
vector <node> block, dp;

int main() {
	int n, nCase = 0;

	while (cin >> n && n) {
		nCase++;

		block.clear();
		block.push_back(node(INF, INF, 0));

		int x[35], y[35], z[35];
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i] >> z[i];
			block.push_back(node(x[i], y[i], z[i]));
			block.push_back(node(x[i], z[i], y[i]));
			block.push_back(node(y[i], z[i], x[i]));
			block.push_back(node(y[i], x[i], z[i]));
			block.push_back(node(z[i], x[i], y[i]));
			block.push_back(node(z[i], y[i], x[i]));
		}

		sort(block.begin() + 1, block.end());

		int height[MAXN];
		memset(height, 0, sizeof(height));
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (block[i].a < block[j].a && block[i].b < block[j].b) {
					if (height[j] + block[i].h > height[i]) {
						height[i] = height[j] + block[i].h;
					}
				}
			}
		}

		int ans = 0;
		for (int i = 1; i < block.size(); i++) {
			if (height[i] > ans)
				ans = height[i];
		}

		cout << "Case " << nCase << ": maximum height = " << ans << endl;
	}
	return 0;
}