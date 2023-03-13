/*
Date : 2023-03-13
*/

#include <iostream>
using namespace std;


int p[8], N;
bool chk[8];

void f(int index) {
	if (index == N) {
		for (int i = 0; i < N; ++i) {
			cout << p[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int x = 1; x <= N; ++x) {
			if (chk[x - 1]) continue;
			chk[x - 1] = true; p[index] = x;
			f(index + 1);
			chk[x - 1] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	f(0);

	return 0;
}
