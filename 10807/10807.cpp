/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 100

int countV(int list[], int n, int v) {
	int count = 0;

	for (int i = 0; i < n; ++i) {
		if (list[i] == v) ++count;
	}

	return count;
}

int main(int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, v;
	int arr[MAX_SIZE];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cin >> v;

	cout << countV(arr, n, v);

	return 0;
}
