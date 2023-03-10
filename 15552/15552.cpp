/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int count, a, b;

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> count;

	for (int i = 0; i < count; ++i) {
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}
