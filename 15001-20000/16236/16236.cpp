/*
2023. 8. 8.
visited를 통한 거리 기록, 탐색 시도 시 거리 값 비교하고 더 작으면 탐색
priority_queue를 이용해 최상단, 왼쪽에 있는 먹이를 우선시 함.
*/

#include <iostream>
using namespace std;
// #include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
// #include <map>
// #include <deque>
#define INF 1000

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int N, mp[20][20], visited[20][20];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int ti, tj;

// 상어 정보
int sz, timer, ate;
pair<int, int> curPos;

void search(int i, int j, int dist = 0) {
    visited[i][j] = dist;
    ++dist;
    for (int z = 0; z < 4; ++z) {
        ti = i + dy[z], tj = j + dx[z];
        if (0 <= ti && ti < N && 0 <= tj && tj < N &&
        mp[ti][tj] <= sz && visited[ti][tj] > dist) {
            if (0 < mp[ti][tj] && mp[ti][tj] < sz) {
                pq.push({dist, {ti, tj}});
            } else {
                search(ti, tj, dist);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    sz = 2;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = INF;
            cin >> mp[i][j];
            if (mp[i][j] == 9) {
                curPos = {i, j};
                mp[i][j] = 0;
            }
        }
    }

    search(curPos.first, curPos.second);

    while (!pq.empty()) {
        timer += pq.top().first;
        ++ate;

        if (ate == sz) {
            ate = 0;
            ++sz;
        }

        curPos = pq.top().second;

        mp[curPos.first][curPos.second] = 0;

        while (!pq.empty()) pq.pop();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                visited[i][j] = INF;
            }
        }
        search(curPos.first, curPos.second);
    }

    cout << timer;

    return 0;
}