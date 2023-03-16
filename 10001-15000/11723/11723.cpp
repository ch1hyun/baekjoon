/*
Date : 2023-03-16
*/

#include <iostream>
using namespace std;
#include <array>

array<int, 20> arr;
int M,num, cnt = 0;
string op;

void Add(int x);
void Remove(int x);
int Check(int x, int mode);
void Toggle(int x);
void All();
void Empty();
void PrintArr();

void Add(int x) {
	if (cnt == 20) return;
	arr[cnt++] = x;
}
void Remove(int x) {
	int tmp = Check(x, 0);
	if (tmp == -1) return;
	for (int i = tmp; i < cnt - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	--cnt;
}
int Check(int c, int mode) {
	for (int i = 0; i < cnt; ++i) {
		if (arr[i] == c) {
			if (mode == 1) cout << 1 << "\n";
			return i;
		}
	}
	if (mode == 1) cout << 0 << "\n";
	return -1;
}
void Toggle(int x) {
	if (Check(x, 0) == -1) Add(x);
	else Remove(x);
}
void All() {
	for (int i = 0; i < 20; ++i) {
		arr[i] = i + 1;
	}
	cnt = 20;
}
void Empty() {
	arr = { 0 };
	cnt = 0;
}

void PrintArr() {
	for (int i = 0; i < cnt; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> M;

	for (int k = 0; k < M; ++k) {
		cin >> op;
		if (op == "all") { All(); continue; }
		else if (op == "empty") { Empty(); continue; }

		cin >> num;

		if (op == "add") {
			Add(num);
		}
		else if (op == "remove") {
			Remove(num);
		}
		else if (op == "check") {
			Check(num, 1);
		}
		else if (op == "toggle") {
			Toggle(num);
		}
	}

	return 0;
}
