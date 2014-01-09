#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//const int MAXN = 30010;
//const int money[11] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
const int MAXN = 6010;
const int money[11] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };
long long dp[MAXN];

int main() {
	double n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < 11; i++) {
		for (int v = money[i]; v < MAXN; v++) {
			dp[v] += dp[v - money[i]];
		}
	}
	while (cin >> n && n) {
		cout << setw(6) << setprecision(2) << fixed << n;
		//cout << setw(17) << dp[int(n + 0.005) * 100] << endl;
		cout << setw(17) << dp[int(n * 20)] << endl;
	}
	return 0;
}