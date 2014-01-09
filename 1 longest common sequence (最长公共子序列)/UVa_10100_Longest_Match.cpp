#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#define max(a,b) ((a) > (b) ? (a): (b))
using namespace std;
const int MAXN = 1010;
int f[MAXN][MAXN];

int main() {
	string st1, st2;
	int nCase = 0;
	while (getline(cin, st1)) {
		nCase++;
		memset(f, 0, sizeof(f));
		getline(cin, st2);
		string a[MAXN], b[MAXN];
		int index = 0, i = 0, cnta = 0, cntb = 0;
		while (i < st1.length()) {
			if (isalpha(st1[i]) || isdigit(st1[i])) {
				i++;
			} else {
				a[cnta++] = st1.substr(index, i - index);
				while (i < st1.length() && !isalpha(st1[i]) && !isdigit(st1[i])) i++;
				index = i;
			}
		}
		if (index != i) a[cnta++] = st1.substr(index, i - index);

		index = 0, i = 0;
		while (i < st2.length()) {
			if (isalpha(st2[i]) || isdigit(st2[i])) {
				i++;
			} else {
				b[cntb++] = st2.substr(index, i - index);
				while (i < st2.length() && !isalpha(st2[i]) && !isdigit(st2[i])) i++;
				index = i;
			}
		}
		if (index != i) b[cntb++] = st2.substr(index, i - index);

		for (int i = 1; i <= cnta; i++) {
			for (int j = 1; j <= cntb; j++) {
				if (a[i - 1] == b[j - 1]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				} else {
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				}
			}
		}

		cout << setw(2) << nCase << ". ";
		if (st1.length() == 0 || st2.length() == 0) {
			cout << "Blank!" << endl;
		} else {
			cout << "Length of longest match: " << f[cnta][cntb] << endl;
		}
	}
	return 0;
}