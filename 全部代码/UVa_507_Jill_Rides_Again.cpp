#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int nCase, cnt = 0;
	cin >> nCase;
	while (nCase--) {
		cnt++;
		int n;
		cin >> n;
		int x, y, index, sum, ans;
		index = x = ans = sum = 0;

		for (int i = 0; i < n - 1; i++) {
			int a;
			cin >> a;
			sum += a;
			if (sum < 0) {
				index = i + 1;
				sum = 0;
				continue;
			}
			if (sum > ans || (sum == ans && index == x)) {
				x = index;
				y = i;
				ans = sum;
			}
		}

		if (ans == 0)
			printf("Route %d has no nice parts\n", cnt);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", cnt, x + 1, y + 2);
	}
	return 0;
}