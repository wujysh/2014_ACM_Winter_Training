#include <iostream>
using namespace std;

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int s, n, max = 0, min = 0;
		cin >> s >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x = (x < (s - x)) ? x : (s - x);
			if (x > min) {
				min = x;
			}
			if (s - x > max) {
				max = s - x;
			}
		}
		cout << min << " " << max << endl;

	}
	return 0;
}