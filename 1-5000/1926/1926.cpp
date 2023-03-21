/*
Date : 2023-03-21
*/

#include <iostream>
using namespace std;
#include <queue>
#include <array>

int arr[501][501], mX[3] = {-1, 0, 1}, mY[3] = {-1, 0, 1};
int n, m, cnt, maxSize = 0, cntPic = 0;
bool chk[501][501];


void bfs(int sX, int sY) {
    queue<array<int, 2>> q;
    array<int, 2> f;
    chk[sY][sX] = true;
    q.push({sY, sX});

    while (!q.empty()) {
        f = q.front();
        sY = f[0], sX = f[1];
        ++cnt;
        q.pop();

        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != 1 && j == 1 || i == 1 && j != 1) {
                    if (sX + mX[i] < 1 || sX + mX[i] > m) continue;
                    if (sY + mY[j] < 1 || sY + mY[j] > n) continue;
                    if (chk[sY + mY[j]][sX + mX[i]]) continue;
                    if (arr[sY + mY[j]][sX + mX[i]] != 1) continue;

                    chk[sY + mY[j]][sX + mX[i]] = true;
                    
                    q.push({sY + mY[j], sX + mX[i]});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i =1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (chk[i][j]) continue;
            if (arr[i][j] != 1) continue;

            cnt = 0;
            bfs(j, i);
            if (cnt > maxSize) maxSize = cnt;
            ++cntPic;
        }
    }

    cout << cntPic << "\n" << maxSize;

    return 0;
}
