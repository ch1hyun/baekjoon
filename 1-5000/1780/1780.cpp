/*
Date : 2023-03-17
*/

#include <iostream>
using namespace std;
#include <cmath>

int N, arr[2187][2187], sum = 0, mCnt = 0, zCnt = 0, pCnt = 0;

void f(int x1, int x2, int y1, int y2) {
	bool mFlag = true, pFlag = true, zFlag = true;
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			if (arr[i][j] != -1) mFlag = false;
			if (arr[i][j] != 0) zFlag = false;
			if (arr[i][j] != 1) pFlag = false;
		}
	}

	if (mFlag) {
		++mCnt; return;
	}
	else if (zFlag) {
		++zCnt; return;
	}
	else if (pFlag) {
		++pCnt; return;
	}

	int sliceX = (x2 - x1 + 1) / 3;
	int sliceY = (y2 - y1 + 1) / 3;
	f(x1, x1 + sliceX - 1, y1, y1 + sliceY - 1);
	f(x1, x1 + sliceX - 1, y1 + sliceY, y1 + sliceY * 2 - 1);
	f(x1, x1 + sliceX - 1, y1 + sliceY * 2, y1 + sliceY * 3 - 1);
	f(x1 + sliceX, x1 + sliceX * 2 - 1, y1, y1 + sliceY - 1);
	f(x1 + sliceX, x1 + sliceX * 2 - 1, y1 + sliceY, y1 + sliceY * 2 - 1);
	f(x1 + sliceX, x1 + sliceX * 2 - 1, y1 + sliceY * 2, y1 + sliceY * 3 - 1);
	f(x1 + sliceX * 2, x1 + sliceX * 3 - 1, y1, y1 + sliceY - 1);
	f(x1 + sliceX * 2, x1 + sliceX * 3 - 1, y1 + sliceY, y1 + sliceY * 2 - 1);
	f(x1 + sliceX * 2, x1 + sliceX * 3 - 1, y1 + sliceY * 2, y1 + sliceY * 3 - 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> arr[i][j];
	}

	f(0, N - 1, 0, N - 1);

	cout << mCnt << "\n";
	cout << zCnt << "\n";
	cout << pCnt;

	return 0;
}
