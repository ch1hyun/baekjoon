/*
Date : 2023-03-14
*/

#include <iostream>
using namespace std;

int n, p[11], o[10], oa[10];
bool chk[10];
int mx = -2147483648, mn = 2147483647;

void compare(int t) {
	if (mx < t) mx = t;
	if (mn > t) mn = t;
}

void calculate() {
	int sum = 0;

	for (int i = 0; i < n - 1; ++i) {
		if (i == 0) {
			sum = p[0];
		}
		if (o[oa[i]] == 0) {
			sum += p[i + 1];
		}
		else if (o[oa[i]] == 1) {
			sum -= p[i + 1];
		}
		else if (o[oa[i]] == 2) {
			sum *= p[i + 1];
		}
		else if (o[oa[i]] == 3) {
			if (sum < 0 || p[i + 1] < 0) {
				sum = abs(sum) / abs(p[i + 1]) * -1;
			}
			else {
				sum /= p[i + 1];
			}
		}
	}

	compare(sum);
}

void f(int index) {
	if (index == n - 1) {
		calculate();
	}
	else {
		for (int i = 0; i < n - 1; ++i) {
			if (chk[i]) continue;
			chk[i] = true; oa[index] = i;
			f(index + 1);
			chk[i] = false;
		}
	}
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	int temp = 0, idx = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> temp;
		while (temp != 0) {
			o[idx] = i;
			--temp; ++idx;
		}
	}

	f(0);

	cout << mx << "\n" << mn;

	return 0;
}
