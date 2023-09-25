/*
2023. 8. 30.
*/

#include <iostream>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <map>
// #include <deque>
// #include <cmath>
#define INF 100000;

int N, M, K, a, b, c;
int mp[50][50];
int keyMatch[50][50];
int keyNum;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

string parse;

priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

/* DISJOINT SETS */
int djs[251];

int find(int s) {
    if (djs[s] <= 0) return s;
    else return djs[s] = find(djs[s]);
}

void update(int v1, int v2) {
    v1 = find(v1), v2 = find(v2);

    if (djs[v1] < djs[v2]) {
        djs[v2] = v1;
    } else {
        if (djs[v1] == djs[v2]) {
            --djs[v2];
        }

        djs[v1] = v2;
    }
}
/* END */

void BFS_key(int i, int j) {
    int dist[N][N], k = keyMatch[i][j];
    for (int u = 1; u < N - 1; ++u) {
        for (int v = 1; v < N - 1; ++v) dist[u][v] = INF;
    }
    dist[i][j] = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii>> tmpq;

    tmpq.push({0, i, j});

    while (!tmpq.empty()) {
        tiii tmp = tmpq.top();
        int l = get<0>(tmp), i = get<1>(tmp), j = get<2>(tmp);

        tmpq.pop();

        if (l > dist[i][j]) continue;

        for (int z = 0; z < 4; ++z) {
            int ti = i + dy[z], tj = j + dx[z];
            if (0 < ti && ti < N - 1 && 0 < tj && tj < N - 1 && mp[ti][tj] != 1 && dist[ti][tj] > l + 1) {
                dist[ti][tj] = l + 1;
                if (mp[ti][tj] != 2) tmpq.push({dist[ti][tj], ti, tj});
            }
        }
    } 

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if (keyMatch[i][j] && k != keyMatch[i][j]) {
                pq.push({dist[i][j], k, keyMatch[i][j]});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> parse;

        for (int j = 0; j < N; ++j) {
            if (parse[j] == 'S' || parse[j] == 'K') {
                mp[i][j] = 2;
                keyMatch[i][j] = ++keyNum;
            }
            else mp[i][j] = parse[j] - 48;
        }
    }

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if (keyMatch[i][j]) {
                BFS_key(i, j);

                keyMatch[i][j] = 0;
            }
        }
    }

    ll sum = 0;
    while (!pq.empty()) {
        tiii tmp = pq.top();
        pq.pop();

        int f = get<1>(tmp), s = get<2>(tmp), l = get<0>(tmp);

        if (find(f) == find(s)) continue;

        sum += l;
        update(f, s);
    }

    if (sum < 100000) cout << sum;
    else cout << -1;

    return 0;
}