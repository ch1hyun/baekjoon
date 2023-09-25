/*
2023. 8. 6.
*/

#include <iostream>
using namespace std;
// #include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
#include <map>
// #include <deque>

int N, M, mp[8][8], visited[8][8];
map<int, pair<int, int>> m;
int midx, cnt, cnt1, ti, tj, mx;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    ++cnt;

    q.push({i, j});

    while (!q.empty()) {
        i = q.front().first, j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            ti = i + dy[k], tj = j + dx[k];
            if (0 <= ti && ti < N && 0 <= tj && tj < M && !visited[ti][tj] && !mp[ti][tj]) {
                visited[ti][tj] = 1;
                ++cnt;
                q.push({ti, tj});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mp[i][j];

            if (!mp[i][j]) m[midx++] = {i, j};
            else if (mp[i][j] == 1) ++cnt1;
        }
    }

    for (int i = 0; i < midx - 2; ++i) {
        mp[m[i].first][m[i].second] = 1;
        for (int j = i + 1; j < midx - 1; ++j) {
            mp[m[j].first][m[j].second] = 1;
            for (int k = j + 1; k < midx; ++k) {
                mp[m[k].first][m[k].second] = 1;

                cnt = 0;
                for (int z = 0; z < N; ++z) {
                    memset(visited[z], 0, M * sizeof(int));
                }

                for (int u = 0; u < N; ++u) {
                    for (int v = 0; v < M; ++v) {
                        if (mp[u][v] == 2) bfs(u, v);
                    }
                }

                cnt = N * M - cnt1 - cnt - 3;

                if (mx < cnt) mx = cnt;

                mp[m[k].first][m[k].second] = 0;
            }
            mp[m[j].first][m[j].second] = 0;
        }
        mp[m[i].first][m[i].second] = 0;
    }

    cout << mx;

    return 0;
}