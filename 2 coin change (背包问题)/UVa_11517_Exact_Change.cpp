#include <iostream>
#include <cstring>
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

const int MAXN = 10010;
const int INF = 0x3f;
int f[MAXN];

int main()  {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int s, n, money[100];
		cin >> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> money[i];
		}

		memset(f, INF, sizeof(f));
		f[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int v = MAXN; v >= money[i]; v--) {
				f[v] = min(f[v], f[v - money[i]] + 1);
			}
		}

		for (int i = s; i < MAXN; i++) {
			if (f[i] < 200) {
				cout << i << " " << f[i] << endl;
				break;
			}
		}
	}
	return 0;
}