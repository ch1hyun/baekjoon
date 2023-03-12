/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 100

void putInBasket(int list[], int s, int e, int ball) {
	for (int j = s - 1; j < e; ++j) {
		list[j] = ball;
	}
}

int main(int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int arr[MAX_SIZE] = { 0 };
	int s, e, n, m, ball;

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> s >> e >> ball;
		if (s < 1 || e > n) {
			--i;
		}
		else {
			putInBasket(arr, s, e, ball);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}
