/*
Date : 2023-03-23
*/

#include <iostream>
#include <queue>
using namespace std;

int n, m, arr[1001][1001], mX[3] = {-1, 0, 1}, mY[3] = {-1, 0, 1}, dayCnt = 0;
bool chk[1001][1001], chkFlag;
queue<pair<int,int>> tmt;

void dayOver(queue<pair<int, int>> q) {
    pair<int, int> tmp;
    int sY, sX;
    while (!q.empty()) {
        tmp = q.front();
        sY = tmp.first, sX = tmp.second;
        q.pop();
        tmt.pop();

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j != 1 || i != 1 && j == 1) {
                    if (sX + mX[i] < 1 || sX + mX[i] > m) continue;
                    if (sY + mY[j] < 1 || sY + mY[j] > n) continue;
                    if (arr[sY + mY[j]][sX + mX[i]] != 0) continue;
                    
                    arr[sY + mY[j]][sX + mX[i]] = 1;
                    tmt.push({sY + mY[j], sX + mX[i]});
                }
            }
        }
    }
    ++dayCnt;
}

bool chkTmt() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) tmt.push({i, j});
        }
    }

    while (!tmt.empty()) {
        dayOver(tmt);
        chkFlag = chkTmt();
    }

    if(!chkFlag) cout << "-1";
    else cout << dayCnt - 1;

    return 0;
}
