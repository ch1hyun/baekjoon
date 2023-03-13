#include <iostream>
using namespace std;

int a[130][130];
int cnt0 = 0, cnt1 = 0;

void f(int x1, int x2, int y1, int y2) {
	bool chk0 = true, chk1 = true;
	for (int i = x1 - 1; i < x2; ++i) {
		for (int j = y1 - 1; j < y2; ++j) {
			if (a[i][j] != 0) chk0 = false;
			if (a[i][j] != 1) chk1 = false;
		}
	}
	if (chk0) { cnt0 += 1; return; }
	if (chk1) {cnt1 += 1; return; }

	int xm = (x1 + x2) / 2;
	int ym = (y1 + y2) / 2;
