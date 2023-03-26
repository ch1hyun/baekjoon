/*
Date : 2023-03-26
*/

#include <iostream>
using namespace std;

int arr[51][51], n, m, x, y, p, maxD = 0, sum=0;
int mvX[4] = {1, -1, 0, 0}, mvY[4] = {0, 0, 1, -1};
bool chk[51][51];

void f(int cx, int cy, int drt, int cost = 0, int cnt = 0) {
    if (maxD == sum) return; // 이미 모든 공간을 다 돌았으면 종료
    if (cost == p) {
        if (maxD < cnt) maxD = cnt; // pipe 최대일 시 maxD 업데이트
    } else if (cost > p) {
        cnt -= arr[cx][cy];
        if (maxD < cnt) maxD = cnt; // 비용이 많이 나왔으면 현재 값을 제외한 이전 값으로 maxD를 업데이트
    } else {
        int nx, ny, passBit = 0;
        
        for (int i = 0; i < 4; ++i) {
            ny = cy + mvY[i];
            nx = cx + mvX[i];
            if (ny < 1 || ny > m) {++passBit; continue;}
            if (nx < 1 || nx > n) {++passBit; continue;}
            if (chk[nx][ny]) {++passBit; continue;}

            chk[nx][ny] = true;
            if (drt == 1 && i < 2) f(nx, ny, 0, cost + 2, cnt + arr[nx][ny]); // 이전 방향과 진행 방향이 다르면 +2 (현재 공간 파이프 추가 1개, 다음 공간 파이프 1개)
            else if (drt == 0 && i > 1) f(nx, ny, 1, cost + 2, cnt + arr[nx][ny]);
            else f(nx, ny, drt, cost + 1, cnt + arr[nx][ny]); // 직선 방향이면 +1
            chk[nx][ny] = false;
        }
        if (passBit == 4) { // 더 이상 탐색할 공간이 없을 때 maxD 업데이트
            if (maxD < cnt) maxD = cnt;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {cin >> arr[i][j]; sum += arr[i][j];}
    }
    cin >> x >> y >> p;
    ++x; ++y;

    chk[x][y] = true;
    if (p != 0 && y + 1 <= m) { // 우
        chk[x][y + 1] = true;
        f(x, y + 1, 1, 1, arr[x][y] + arr[x][y + 1]);
        chk[x][y + 1] = false;
    }
    if (p != 0 && y - 1 >= 1) { // 좌
        chk[x][y - 1] = true;
        f(x, y - 1, 1, 1, arr[x][y] + arr[x][y - 1]);
        chk[x][y - 1] = false;
    }
    if (p != 0 && x + 1 <= n) { // 하
        chk[x + 1][y] = true;
        f(x + 1, y, 0, 1, arr[x][y] + arr[x + 1][y]);
        chk[x + 1][y] = false;
    }
    if (p != 0 && x - 1 >= 1) { // 상
        chk[x - 1][y] = true;
        f(x - 1, y, 0, 1, arr[x][y] + arr[x - 1][y]);
        chk[x - 1][y] = false;
    }
    if (p == 0 || (n == 1 && m == 1)) maxD = arr[x][y];

    cout << maxD;

    return 0;
}
