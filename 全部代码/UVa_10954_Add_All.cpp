#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> q;

int main() {
	int n;
	while (cin >> n && n) {
		int sum = 0;
		while (!q.empty()) q.pop();

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			q.push(-x);
		}

		while (q.size() >= 2) {
			int x, y;
			x = -q.top();
			q.pop();
			y = -q.top();
			q.pop();
			q.push(-(x + y));
			sum += x + y;
		}

		cout << sum << endl;
	}
	return 0;
}