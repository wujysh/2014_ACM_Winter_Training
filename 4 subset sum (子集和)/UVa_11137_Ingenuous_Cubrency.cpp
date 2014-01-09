#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10010;
long long dp[MAXN];

int main() {
	int s;
	int cube[30];
	for (int i = 1; i <= 21; i++) {
		cube[i] = i * i * i;
	}

	while (cin >> s) {
		for (int i = 0; i <= s; i++) {
			dp[i] = 1;
		}

		for (int i = 2; i <= 21; i++) {
			for (int v = cube[i]; v <= s; v++) {
				dp[v] += dp[v - cube[i]];
			}
		}

		cout << dp[s] << endl;
	}
	return 0;
}