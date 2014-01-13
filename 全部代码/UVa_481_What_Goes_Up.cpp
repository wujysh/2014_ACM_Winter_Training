#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int INF = 0x7fffffff;
vector <int> dp, a, pre, numPos;
stack <int> ans;

int main() {
	freopen("input.txt", "r", stdin);
	int x;
	pre.clear();
	while (cin >> x) {
		a.push_back(x);
		pre.push_back(-1);
	}

	numPos.clear();
	numPos.push_back(0);
	dp.clear();
	dp.push_back(-INF);

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > dp.back()) {
			pre[i] = numPos.back();
			dp.push_back(a[i]);
			numPos.push_back(i);
		} else {
			vector <int>::iterator it = lower_bound(dp.begin(), dp.end(), a[i]);
			*it = a[i];
			numPos[it - dp.begin()] = i;
			pre[i] = numPos[it - dp.begin() - 1];
		}
	}

	cout << dp.size() - 1 << endl << "-" << endl;
	int p = numPos[dp.size() - 1];
	for (int i = 0; i < dp.size() - 1; i++) {
		ans.push(a[p]);
		p = pre[p];
	}
	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
	//system("pause");
	return 0;
}