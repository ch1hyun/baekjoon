/*
Date : 2023-03-18
*/

#include <iostream>
using namespace std;
#include <string>

int N, D, arr[243][729];

void printStar() {
    string a, b, c;

    for (int p = 0; p < D; ++p) {
        a="", b="", c="";
        for (int j = 0; j < N/3; ++j) {
            if (arr[p][j] == 1) {
                a += "***";
                b += "* *";
                c += "***";
            } else if (arr[p][j] == 0) {
                a += "   ";
                b += "   ";
                c += "   ";
            }
        }
        cout << a << "\n" << b << "\n" << c << "\n";
    }
}

void f(int x1, int x2, int y1, int y2, bool flagP = false) {
    if (x2 - x1 == 2 && y2 - y1 == 2) {
        for (int i = y1; i <= y2; ++i) {
            for (int j = x1; j <= x2; ++j) {
                if (i % 3 == 1 && j % 3 == 1) continue;
                arr[i % D][j] = 1;
            }
        }
        return;
    }

    int sliceX = (x2 - x1 + 1) / 3;
    int sliceY = (y2 - y1 + 1) / 3;

    f(x1, x1 + sliceX - 1, y1, y1 + sliceY - 1);
    f(x1 + sliceX, x1 + sliceX * 2 - 1, y1, y1 + sliceY - 1);
    f(x1 + sliceX * 2, x1 + sliceX * 3 - 1, y1, y1 + sliceY - 1);
    if (flagP) {printStar();}

    f(x1, x1 + sliceX - 1, y1 + sliceY, y1 + sliceY * 2 - 1);
    for (int i = y1 + sliceY; i < y1 + sliceY*2; ++i) {
        for (int j = x1 + sliceX; j < x1 + sliceX*2; ++j) arr[i % (N / 9)][j] = 0;
    }
    f(x1 + sliceX * 2, x1 + sliceX * 3 - 1, y1 + sliceY, y1 + sliceY * 2 - 1);
    if (flagP) printStar();

    f(x1, x1 + sliceX - 1, y1 + sliceY * 2, y1 + sliceY * 3 - 1);
    f(x1 + sliceX, x1 + sliceX * 2 - 1, y1 + sliceY * 2, y1 + sliceY * 3 - 1);
    f(x1 + sliceX * 2, x1 + sliceX * 3 - 1, y1 + sliceY * 2, y1 + sliceY * 3 - 1);
    if (flagP) printStar();

    
}

int main(int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

    cin >> N;
    if (N == 3 || N == 9) D = N / 3;
    else D = N / 9;

    if (N == 3) {arr[0][0] = 1; printStar();}
    else f(0, N/3 - 1, 0, N/3 - 1, true);

    if (N == 9) printStar();

	return 0;
}
