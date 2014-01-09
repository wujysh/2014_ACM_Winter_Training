#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

long long dp[20][20];
char line[255];
int n;

/* DP(x, c)
   x : previous queen's row; 
   c : number of columns need to process
*/
long long DP(int x, int c) {
	if (dp[x][c] != -1) return dp[x][c];
	if (c == 0) return dp[x][c] = 1;
	dp[x][c] = 0;
	if (line[n - c] == '?') {
		for (int i = 1; i <= n; i++)
			if (abs(i - x) >= 2 || x == 0)
				dp[x][c] += DP(i, c - 1);
	} else {
		int newi;
		if (isalpha(line[n - c]))
			newi = line[n - c] - 'A' + 10;
		if (isdigit(line[n - c]))
			newi = line[n - c] - '0';
		if (abs(x - newi) >= 2 || x == 0)
			dp[x][c] += DP(newi, c - 1);
	}
	return dp[x][c];
}

int main() {
	while (scanf("%s", line) == 1) {
		memset(dp, -1, sizeof(dp));
		n = strlen(line);
		cout << DP(0, n) << endl;
	}
	return 0;
}