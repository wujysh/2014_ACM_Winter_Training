#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		vector <int> stack, sortedStack;
		stringstream ss(line);
		int x;
		while (ss >> x) {
			stack.push_back(x);
		}

		for (int i = 0; i < stack.size(); i++) {
			if (i) cout << " ";
			cout << stack[i];
		}
		cout << endl;

		sortedStack = stack;
		sort(sortedStack.begin(), sortedStack.end());

		for (int i = stack.size() - 1; i >= 0; i--) {
			if (stack[i] != sortedStack[i]) {
				vector <int>::iterator it;
				it = find(stack.begin(), stack.end(), sortedStack[i]);
				if (it == stack.begin()) {
					reverse(stack.begin(), stack.begin() + i + 1);
					cout << stack.size() - i << " ";
				} else {
					reverse(stack.begin(), it + 1);
					cout << stack.end() - it << " ";
					reverse(stack.begin(), stack.begin() + i + 1);
					cout << stack.size() - i << " ";
				}
			}
		}

		cout << 0 << endl;
	}
	return 0;
}