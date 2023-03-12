/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 100

void swapBasket(int list[], int from, int to) {
	int temp;
	temp = list[from];
	list[from] = list[to];
	list[to] = temp;
}

int main(int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int arr[MAX_SIZE];
	int n, m, from, to;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; ++i) {
		cin >> from >> to;
		if (from < 1 || to > n) {
			--i;
		}
		else {
			swapBasket(arr, from - 1, to - 1);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}
