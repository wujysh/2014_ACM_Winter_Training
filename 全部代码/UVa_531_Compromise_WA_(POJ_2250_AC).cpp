#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
const int MAXN = 110;

string word[2][MAXN];
int cnt[2], f[MAXN][MAXN], path[MAXN][MAXN];
bool flag = false;

void processline(string str, int num) {
	stringstream ss(str);
	while (ss >> word[num][cnt[num]]) {
		if (word[num][cnt[num]] != "") cnt[num]++;
	}
}

void printpath(int x, int y) {
	if (!x || !y) return;
	if (path[x][y] == 0) {
		printpath(x - 1, y - 1);
		if (!flag) flag = true;
		else cout << " ";
		cout << word[0][x];
	} else if (path[x][y] == -1) {
		printpath(x - 1, y);
	} else if (path[x][y] == 1) {
		printpath(x, y - 1);
	}
}

int main() {
	string str;
	while (getline(cin, str)) {
		//memset(word, 0, sizeof(word));
		cnt[0] = cnt[1] = 1;
		memset(f, 0, sizeof(f));
		memset(path, 0, sizeof(path));

		processline(str, 0);
		while (getline(cin, str) && str != "#") {
			processline(str, 0);
		}
		while (getline(cin, str) && str != "#") {
			processline(str, 1);
		}

		for (int i = 1; i <= cnt[0]; i++) {
			for (int j = 1; j <= cnt[1]; j++) {
				if (word[0][i] == word[1][j]) {
					f[i][j] = f[i - 1][j - 1] + 1;
					path[i][j] = 0;
				} else if (f[i - 1][j] > f[i][j - 1]) {
					f[i][j] = f[i - 1][j];
					path[i][j] = -1;
				} else {
					f[i][j] = f[i][j - 1];
					path[i][j] = 1;
				}
			}
		}

		flag = false;
		printpath(cnt[0], cnt[1]);
		cout << endl;
	}
	return 0;
}