/*
Date : 2023-03-14
*/

#include <iostream>
using namespace std;

int n, s;
int res = 0;
int p[20];

void f(int index, int count = 0, int sum = 0) {
	if (index == n) {
		if (sum == s && count != 0) {
			++res;
			return;
		}
		else {
			return;
		}
	}
	else {
		f(index + 1, count + 1, sum + p[index]);
		f(index + 1, count, sum);
	}
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	f(0);

	cout << res;

	return 0;
}
