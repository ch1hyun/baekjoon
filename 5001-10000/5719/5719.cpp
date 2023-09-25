/*
2023. 8. 6.
*/
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
#include <map>
// #include <deque>
#define INF 9876543

int N, M, S, D, U, V, P, tmp;
vector<pair<int, int>> v[500];
int dist[500], way[500];
map<pair<int, int>, int> m;
queue<int> before[500]; // 현재 정점 (=index)와 이전 정점 (value)의 관계

void block(int t) {
    int tmp;
    while (!before[t].empty()) {
        tmp = before[t].front();
        before[t].pop();
        // tmp -> t를 막음.

        m[{tmp, t}] = 1;
        block(tmp);
    }
}

void bfs(int st) {
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, st});
    int cur, curd, nxt, nxtd;

    while (!pq.empty()) {
        curd = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (curd > dist[cur]) continue;

        for (pair<int, int> i : v[cur]) {
            nxt = i.first, nxtd = i.second;
            if (!m[{cur, nxt}] && dist[nxt] > dist[cur] + nxtd) {
                // 이전 정점 초기화
                while (!before[nxt].empty()) before[nxt].pop();
                before[nxt].push(cur);

                dist[nxt] = dist[cur] + nxtd;
                way[nxt] = cur;
                pq.push({dist[nxt], nxt});
            } else if (!m[{cur, nxt}] && dist[nxt] == dist[cur] + nxtd) {
                // 이전 정점 추가
                before[nxt].push(cur);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> N >> M;
        if (!N && !M) break;

        cin >> S >> D;
        for (int i = 0; i < M; ++i) {
            cin >> U >> V >> P;

            v[U].push_back({V, P});
        }

        for (int i = 0; i < N; ++i) {
            dist[i] = INF;
            way[i] = -1;
        }

        bfs(S);

        while (!before[D].empty()) {
            tmp = before[D].front();
            before[D].pop();

            m[{tmp, D}] = 1;

            block(tmp);
        }

        for (int i = 0; i < N; ++i) {
            dist[i] = INF;
        }

        bfs(S);

        if (dist[D] == INF) cout << -1 << "\n";
        else cout << dist[D] << "\n";

        //reset
        for (int i = 0; i < N; ++i) {
            v[i].clear();
            while (!before[i].empty()) before[i].pop();
        }
        m.clear();
    }

    return 0;
}