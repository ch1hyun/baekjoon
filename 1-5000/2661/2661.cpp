/*
Date : 2023-03-17
*/

#include <iostream>
using namespace std;
#include <string>

int N;
bool endFlag = false;

void f(string temp = "") {
	if (endFlag) return;

	int len = temp.length();

	for (int i = len - 1; i > len / 2 - 1; --i) {
		if ((len - i) * 2 > len) break;
		if (temp.substr(i, len - i) == temp.substr(i * 2 - len, len - i)) return;
	}
	if (len == N) {
		endFlag = true;
		cout << temp;
		return;
	}

	f(temp + "1");
	f(temp + "2");
	f(temp + "3");
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	f();

	return 0;
}
