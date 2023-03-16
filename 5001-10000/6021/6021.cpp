/*
Date : 2023-03-17
*/

#include <iostream>
using namespace std;

int N,arr[2200], sum = 0;

void f(int start, int end) {
	if (end - start == 1) {
		sum += arr[start] * arr[end];
		return;
	}
	if (end - start == 0) return;

	int middle = (start + end) / 2;

	f(start, middle);
	f(middle + 1, end);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i) arr[i] = i + 1;

	f(0, N - 1);

	cout << sum;

	return 0;
}
