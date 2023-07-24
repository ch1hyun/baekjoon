#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset

int sdoku[10][10];
int usedr[10][10];
int usedc[10][10];

bool checkPoint(int x, int y, int n); 

void f(int x, int y) {
    if (!sdoku[y][x]) {
        for (int i = 1; i <= 9; ++i) {
            if (usedr[y][i] || usedc[x][i]) continue;
            if (checkPoint(x, y, i)) {
                sdoku[y][x] = i;
                usedc[x][i] = usedr[y][i] = 1;
                f(x, y);
                usedc[x][i] = usedr[y][i] = 0;
                sdoku[y][x] = 0;
            }
        }
    } else {
        if (x == 9 && y == 9) {
            for (int i = 1; i <= 9; ++i) {
                for (int j = 1; j <= 9; ++j) {
                    cout << sdoku[i][j] << " ";
                }
                cout << "\n";
            }
            exit(0);
        }
        else if (x == 9) {
            f(1, y + 1);
        } else {
            f(x + 1, y);
        }
    }
}

bool checkPoint(int x, int y, int n) {
    // check box area
    int used[10];
    memset(used, 0, 10 * sizeof(int));

    for (int i = ((y - 1) / 3) * 3 + 1; i <= ((y - 1) / 3 + 1) * 3; ++i) {
        for (int j = ((x - 1) / 3) * 3 + 1; j <= ((x - 1) / 3 + 1) * 3; ++j) {
            if (sdoku[i][j]) used[sdoku[i][j]] = 1;
        }
    }

    if (used[n]) return false;
    else return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> sdoku[i][j];
            if (sdoku[i][j]) {
                usedr[i][sdoku[i][j]] = 1;
                usedc[j][sdoku[i][j]] = 1;
            }
        }
    }

    f(1, 1);

    return 0;
}