/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 100

void reverseBasket(int list[], int s, int e) {
	while (s < e) {
		swap(list[(s++)-1], list[(e--)-1]);

	}
}

int main(int argc, char const* argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int n = 0, m = 0, s = 0, e = 0, arr[MAX_SIZE] = {0};
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; ++i) {
		cin >> s >> e;
		reverseBasket(arr, s, e);
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}
