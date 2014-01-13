#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 110;

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int n;
		string word[MAXN];
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> word[i];
		}

		sort(word, word + n);

		int ans = word[0].length();

		for (int i = 1; i < n; i++) {
			int index = word[i - 1].length();
			for (int j = 0; j < word[i - 1].length(); j++) {
				if (word[i - 1][j] != word[i][j]) {
					index = j;
					break;
				}
			}
			ans += word[i].length() - index;
		}

		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			cout << word[i] << endl;
		}
	}
	return 0;
}