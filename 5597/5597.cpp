/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 30

int main(int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, arr[MAX_SIZE] = { 0 };

	for (int i = 0; i < 28; ++i) {
		cin >> n;
		arr[n - 1] = 1;
	}

	for (int i = 0; i < MAX_SIZE; ++i) {
		if (arr[i] == 0) cout << i + 1 << "\n";
	}

	return 0;
}
