#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int c, s, nCase = 0;
	while (cin >> c >> s) {
		nCase++;
		vector <int> specimen, chamber[6];
		int sum = 0;
		double ave;
		for (int i = 0; i < s; i++) {
			int x;
			cin >> x;
			sum += x;
			specimen.push_back(x);
		}
		ave = (double)sum / c;

		for (int i = 0; i < 2 * c - s; i++) {
			specimen.push_back(0);
		}

		sort(specimen.begin(), specimen.end());
		for (int i = 0; i < specimen.size() / 2; i++) {
			if (specimen[i])
				chamber[i].push_back(specimen[i]);
			if (specimen[specimen.size() - i - 1])
				chamber[i].push_back(specimen[specimen.size() - i - 1]);
		}

		double imbalance = 0.0;
		cout << "Set #" << nCase << endl;
		for (int i = 0; i < c; i++) {
			cout << setw(2) << i << ":";
			int sum = 0;
			for (int j = 0; j < chamber[i].size(); j++) {
				cout << " " << chamber[i][j];
				sum += chamber[i][j];
			}
			imbalance += fabs(double(sum) - ave);
			cout << endl;
		}

		cout << "IMBALANCE = " << setprecision(5) << fixed << imbalance << endl;
		cout << endl;
	}
	return 0;
}