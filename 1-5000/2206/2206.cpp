/*
Date : 2023-03-25
가중치가 없는 그래프의 최단 거리를 구할 때는 무조건 BFS.
이 문제는 벽을 부순 상황, 부수지 않고 기회가 남아있는 상황으로 분류해야 함. <- 좌표만 지정해서는 해결 불가능. (flag를 사용한다고 하더라도 1000 * 1000 ^ 2의 시간 복잡도가 발생함.)
*/

#include <iostream>
using namespace std;
#include <string>
#include <queue>

int n, m, arr[1001][1001], dist[1001][1001][2], mvX[4] = {1, -1, 0, 0}, mvY[4] = {0, 0, 1, -1};
string tmpS;
vector<int> tmpV;

void printArr0();
void printArr1();

int f(pair<int,int> p) {
    queue<vector<int>> q;
    int nX, nY;
    q.push({p.first, p.second, 0});
    dist[1][1][0] = 1;

    while (!q.empty()) {
        tmpV = q.front();
        q.pop();
        if (tmpV[0] == n && tmpV[1] == m) return dist[tmpV[0]][tmpV[1]][tmpV[2]];

        for (int i = 0; i < 4; ++i) {
            nY = tmpV[0] + mvY[i];
            if (nY < 1 || nY > n) continue;
            nX = tmpV[1] + mvX[i];
            if (nX < 1 || nX > m) continue;

            if (dist[nY][nX][tmpV[2]]) continue;

            if (arr[nY][nX] == 0) {
                dist[nY][nX][tmpV[2]] = dist[tmpV[0]][tmpV[1]][tmpV[2]] + 1;
                q.push({nY, nX, tmpV[2]});
            } else if (arr[nY][nX] == 1 && tmpV[2] == 0) {
                dist[nY][nX][1] = dist[tmpV[0]][tmpV[1]][tmpV[2]] + 1;
                q.push({nY, nX, 1});
            }
        }
    }
    return -1;
}
void printArr0() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dist[i][j][0] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}void printArr1() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dist[i][j][1] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> tmpS;
        for (int j = 1; j <= m; ++j) {
            arr[i][j] = tmpS[j - 1] - '0';
        }
    }

    cout << f({1,1});
    
    return 0;
}
