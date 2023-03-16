/*
Date : 2023-03-16
*/

#include <iostream>
using namespace std;
#include <array>

int N,result = 0;
bool chk[14];
int queen[14];

bool isPossible(int n, int i) {
	for (int j = 0; j < n; ++j) {
		if (queen[j] + n - j == i) return false;
		if (queen[j] - n + j == i) return false;
	}
	return true;
}

void f(int n) {
	if (n == N) {
		++result;
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (chk[i]) continue;
			if (isPossible(n, i)) {
				queen[n] = i;
				chk[i] = true;
				f(n + 1);
				chk[i] = false;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	f(0);
	cout << result;
}
