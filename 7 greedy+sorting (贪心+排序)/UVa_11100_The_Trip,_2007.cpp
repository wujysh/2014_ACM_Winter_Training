#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		map <int, int> count;
		vector <int> bag;
		vector <vector <int> > piece;
		int max = 1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			bag.push_back(x);
			if (count.find(x) != count.end()) {
				count[x]++;
				if (count[x] > max) max = count[x];
			} else {
				count[x] = 1;
			}
		}
		sort(bag.begin(), bag.end());

		piece.resize(max);
		int j = 0;
		for (int i = 0; i < bag.size(); i++) {
			piece[j].push_back(bag[i]);
			j = (j + 1) % max;
		}

		cout << max << endl;
		for (int i = 0; i < piece.size(); i++) {
			for (int j = 0; j < piece[i].size(); j++) {
				if (j) cout << " ";
				cout << piece[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}