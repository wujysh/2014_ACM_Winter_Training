#include <iostream>
#include <cstring>
#include <string>
#define max(a,b) ((a) > (b) ? (a): (b))
using namespace std;

int f[1010][1010];

int main() {
	string st1, st2;
	while (getline(cin, st1)) {
		memset(f, 0, sizeof(f));
		getline(cin, st2);
		for (int i = 1; i <= st1.length(); i++) {
			for (int j = 1; j <= st2.length(); j++) {
				if (st1[i - 1] == st2[j - 1]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				} else {
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				}
			}
		}
		cout << f[st1.length()][st2.length()] << endl;
	}
	return 0;
}