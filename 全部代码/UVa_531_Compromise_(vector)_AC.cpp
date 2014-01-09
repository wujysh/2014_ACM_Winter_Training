#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
const int MAXN = 110;

string word[2][MAXN];
int cnt[2], f[MAXN][MAXN];
vector <string> v[MAXN][MAXN];

void processline(string str, int num) {
	stringstream ss(str);
	while (ss >> word[num][cnt[num]]) {
		if (word[num][cnt[num]] != "") cnt[num]++;
	}
}

int main() {
	string str;
	while (getline(cin, str)) {
		//memset(word, 0, sizeof(word));
		memset(cnt, 0, sizeof(cnt));
		memset(f, 0, sizeof(f));

		processline(str, 0);
		while (getline(cin, str) && str != "#") {
			processline(str, 0);
		}
		while (getline(cin, str) && str != "#") {
			processline(str, 1);
		}

		for (int i = 0; i <= cnt[0]; i++) {
			for (int j = 0; j <= cnt[1]; j++) {
				v[i][j].clear();
			}
		}

		for (int i = 1; i <= cnt[0]; i++) {
			for (int j = 1; j <= cnt[1]; j++) {
				if (word[0][i-1] == word[1][j-1]) {
					f[i][j] = f[i - 1][j - 1] + 1;
					v[i][j] = v[i - 1][j - 1];
					v[i][j].push_back(word[0][i - 1]);
				} else if (f[i - 1][j] > f[i][j - 1]) {
					f[i][j] = f[i - 1][j];
					v[i][j] = v[i - 1][j];
				} else {
					f[i][j] = f[i][j - 1];
					v[i][j] = v[i][j - 1];
				}
			}
		}

		for (int i = 0; i < v[cnt[0]][cnt[1]].size(); i++) {
			if (i != 0) cout << " ";
			cout << v[cnt[0]][cnt[1]][i];
		}
		cout << endl;
	}
	return 0;
}