#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int order, t, s;
	node(int o1, int t1, int s1) {
		order = o1;  t = t1;  s = s1;
	}
	friend bool operator < (node a, node b) {
		return a.t * b.s < b.t * a.s;
	}
};

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int n;
		cin >> n;
		vector <node> job;
		for (int i = 1; i <= n; i++) {
			int t, s;
			cin >> t >> s;
			job.push_back(node(i, t, s));
		}
		sort(job.begin(), job.end());

		for (int i = 0; i < job.size(); i++) {
			if (i) cout << " ";
			cout << job[i].order;
		}
		cout << endl;
		if (nCase) cout << endl;
	}
	return 0;
}