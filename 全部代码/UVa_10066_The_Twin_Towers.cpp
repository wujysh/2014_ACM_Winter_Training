#include <iostream>
#include <cstring>
#define max(a,b) ((a) > (b) ? (a): (b))
using namespace std;

int f[110][110];

int main() {
	int n1, n2, nCase = 0;;
	while (cin >> n1 >> n2 && (n1 || n2)) {
		nCase++;
		memset(f, 0, sizeof(f));

		int a[110], b[110];
		for (int i = 0; i < n1; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n2; i++) {
			cin >> b[i];
		}
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				if (a[i-1] == b[j-1]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				} else {
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				}
			}
		}
		cout << "Twin Towers #" << nCase << endl;
		cout << "Number of Tiles : " << f[n1][n2] << endl;
		cout << endl;
	}

	return 0;
}