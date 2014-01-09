#include <iostream>
#include <string>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int r, c, a[105][105], f[105][105];

void dfs(int x, int y, int step) {
	if (f[x][y] >= step) return;
	f[x][y] = step;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
			if (a[nx][ny] < a[x][y] && f[nx][ny] < step + 1) {
				dfs(nx, ny, step + 1);
			}
		}
	}
}

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		string name;

		cin >> name >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> a[i][j];
				f[i][j] = 0;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (f[i][j] == 0) {
					dfs(i, j, 1);
				}
			}
		}

		int max = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (f[i][j] > max)
					max = f[i][j];
			}
		}
		cout << name << ": " << max << endl;
	}
}