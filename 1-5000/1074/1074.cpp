/*
Date : 2023-03-17
*/

#include <iostream>
using namespace std;
#include <cmath>

int N, r, c, sum = 0;
bool endFlag = false;

void f(int x1, int x2, int y1, int y2){
	if (endFlag) return;
	if (x2 - x1 == 1 && y2 - y1 == 1) {
		sum += (r % 2) * 2 + c % 2;

		endFlag = true; return;
	}

	int middleX = (x1 + x2) / 2;
	int middleY = (y1 + y2) / 2;

	if (c <= middleX && r <= middleY) {
		f(x1, middleX, y1, middleY);
	}
	else if (c > middleX && r <= middleY) {
		sum += pow((x2 - x1 + 1) / 2, 2);
		f(middleX + 1, x2, y1, middleY);
	}
	else if (c <= middleX && r > middleY) {
		sum += pow((x2 - x1 + 1) / 2, 2) * 2;
		f(x1, middleX, middleY + 1, y2);
	}
	else if (c > middleX && r > middleY) {
		sum += pow((x2 - x1 + 1) / 2, 2) * 3;
		f(middleX + 1, x2, middleY + 1, y2);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> r >> c;

	f(0, pow(2, N) - 1, 0, pow(2, N) - 1);

	cout << sum;

	return 0;
}
