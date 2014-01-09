#include <iostream>
#include <string>
using namespace std;

const int MAXN = 30;

int MaxSum(int n, int a[MAXN], int &start, int &end) {
	int sum = 0;
	int b = 0;
	for (int i = 1; i <= n; i++) {
		if (b > 0)b += a[i];
		else {
			b = a[i];
			start = i;
			end = i;
		}
		if (b > sum) {
			sum = b;
			end = i;
		}
	}
	return sum;
}

int MaxSum2(int m, int n, int a[MAXN][MAXN], int &x1, int &y1, int &x2, int &y2) {
	int sum = 0, count = 0, start, end;
	//x1=y1=x2=y2=0;
	int *b = new int[n + 1];
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++)
			b[k] = 0;
		for (int j = i; j <= m; j++) {
			for (int k = 1; k <= n; k++)
				b[k] += a[j][k];
			int max = MaxSum(n, b, start, end);
			if (max > sum) {
				if (count == 0) {
					x1 = j;
					y1 = start;
					count++;
				}
				sum = max;
				x2 = j;
				y2 = end;
			} else {
				count = 0;
			}
		}
	}
	return sum;
}

int main() {
	int nCase;
	cin >> nCase;
	cin.ignore();
	while (nCase--) {
		cin.ignore();

		int a[MAXN][MAXN];
		int x1, y1, x2, y2;

		string line;
		getline(cin, line);
		int len = line.length();
		for (int i = 1; i <= len; i++) {
			a[1][i] = line[i - 1] - '0';
			if (a[1][i] == 0) a[1][i] = -10000;
		}
		for (int i = 2; i <= len; i++) {
			getline(cin, line);
			for (int j = 1; j <= len; j++) {
				a[i][j] = line[j - 1] - '0';
				if (a[i][j] == 0) a[i][j] = -10000;
			}
		}

		int sum = MaxSum2(len, len, a, x1, y1, x2, y2);
		cout << sum << endl;
		if (nCase >= 1) cout << endl;
	}
	return 0;
}