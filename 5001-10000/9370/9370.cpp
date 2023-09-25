#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <map>
// #include <deque>
#define INF 98765432

int T, n, m, t, s, g, h, a, b, d, tmp;
vector<int> destination;
vector<pair<int, int>> v[2001];
int dist[2001], ddist[2001];
int dist1, dist2;
bool found;
priority_queue<int, vector<int>, greater<int>> pqout;

void bfs2(int st) {
    ddist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, st});

    int curd, cur, nxtd, nxt;
    while (!pq.empty()) {
        curd = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (curd > ddist[cur]) continue;

        for (pair<int, int> i : v[cur]) {
            nxt = i.first, nxtd = i.second;
            if (ddist[nxt] > ddist[cur] + nxtd) {
                ddist[nxt] = ddist[cur] + nxtd;
                pq.push({ddist[nxt], nxt});
            }
        }
    }
}

void bfs(int st) {
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, st});

    int curd, cur, nxtd, nxt;
    while (!pq.empty()) {
        curd = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (curd > dist[cur]) continue;

        for (pair<int, int> i : v[cur]) {
            nxt = i.first, nxtd = i.second;
            if (dist[nxt] > dist[cur] + nxtd) {
                dist[nxt] = dist[cur] + nxtd;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T-- != 0) {
        found = false;

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> d;

            v[a].push_back({b, d});
            v[b].push_back({a, d});
        }

        for (int i = 0; i < t; ++i) {
            cin >> tmp;
            destination.push_back(tmp);
        }

        // get dist g
        memset(dist, INF, (n + 1) * sizeof(int));
        bfs(s);
        if (dist[h] < dist[g]) {
            tmp = g;
            g = h;
            h = tmp;
        }

        dist1 = dist[g];

        memset(ddist, INF, (n + 1) * sizeof(int));
        bfs2(g);

        dist2 = ddist[h];

        memset(ddist, INF, (n + 1) * sizeof(int));
        bfs2(h);

        for (int i : destination) {
            if (dist[i] == ddist[i] + dist1 + dist2) {
                pqout.push(i);
            }
        }

        if (!pqout.empty()) found = true;
        while (!pqout.empty()) {
            cout << pqout.top() << " ";
            pqout.pop();
        }

        if (found) cout << "\n";

        // reset
        for (int i = 1; i <= n; ++i) {
            v[i].clear();
        }
        destination.clear();
    }

    return 0;
}