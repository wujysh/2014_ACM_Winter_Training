#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int nCase, cnt = 0;
	cin >> nCase;
	while (nCase--) {
		cnt++;
		int n, d;
		vector <int> stone;
		cin >> n >> d;

		stone.push_back(0);
		for (int i = 0; i < n; i++) {
			char a;
			int b;
			cin >> a;
			cin.ignore();
			cin >> b;
			stone.push_back(b);
			if (a == 'B') stone.push_back(b);
		}
		stone.push_back(d);
		//sort(stone.begin(), stone.end()); // already sorted

		int ans = 0;
		for (int i = 3; i < stone.size(); i += 2) {
			if (stone[i] - stone[i - 2] > ans)
				ans = stone[i] - stone[i - 2];
		}
		for (int i = 2; i < stone.size(); i += 2) {
			if (stone[i] - stone[i - 2] > ans)
				ans = stone[i] - stone[i - 2];
		}

		cout << "Case " << cnt << ": " << ans << endl;
	}
	return 0;
}