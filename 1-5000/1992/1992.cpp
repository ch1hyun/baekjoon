/*
Date : 2023-03-17
*/

#include <iostream>
using namespace std;
#include <string>

string result = "";
int N;
string arr[64][64];

void f(int x1, int x2, int y1, int y2) {
	bool zFlag = true, oFlag = true;
	
	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			if (arr[i][j] == "0") oFlag = false;
			if (arr[i][j] == "1") zFlag = false;
			if (!oFlag && !zFlag) break;
		}
		if (!oFlag && !zFlag) break;
	}

	if (oFlag) result += "1";
	else if (zFlag) result += "0";
	else {
		result += "(";
		int middleX = (x1 + x2) / 2, middleY = (y1 + y2) / 2;
		f(x1, middleX, y1, middleY);
		f(middleX + 1, x2, y1, middleY);
		f(x1, middleX, middleY + 1, y2);
		f(middleX + 1, x2, middleY + 1, y2);
		result += ")";
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		for (int j = 0; j < N; ++j) {
			arr[i][j] = tmp[j];
		}
	}

	f(0, N - 1, 0, N - 1);

	cout << result;

	return 0;
}
