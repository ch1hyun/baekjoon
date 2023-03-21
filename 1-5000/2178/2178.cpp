/*
Date : 2023-03-21
*/

#include <iostream>
using namespace std;
#include <queue>
#include <array>

int arr[101][101], distanceM[101][101], mX[3] = {-1, 0, 1}, mY[3] = {-1, 0, 1};
int n, m;
bool chk[101][101];


void bfs(int sX, int sY) {
    queue<array<int, 2>> q;
    array<int, 2> f;
    chk[sY][sX] = true;
    distanceM[sY][sX] = 1;
    q.push({sY, sX});

    while (!q.empty()) {
        f = q.front();
        sY = f[0], sX = f[1];
        q.pop();

        if (sY == n && sX == m) {
            return;
        }

        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != 1 && j == 1 || i == 1 && j != 1) {
                    if (sX + mX[i] < 1 || sX + mX[i] > m) continue;
                    if (sY + mY[j] < 1 || sY + mY[j] > n) continue;
                    if (chk[sY + mY[j]][sX + mX[i]]) continue;
                    if (arr[sY + mY[j]][sX + mX[i]] != 1) continue;

                    chk[sY + mY[j]][sX + mX[i]] = true;
                    distanceM[sY + mY[j]][sX + mX[i]] = distanceM[sY][sX] + 1;
                    
                    q.push({sY + mY[j], sX + mX[i]});
                }
            }
        }
    }
}

int main() {
    string s;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            arr[i][j] = s[j - 1] - '0';
        }
    }

    bfs(1, 1);

    cout << distanceM[n][m];

    return 0;
}
