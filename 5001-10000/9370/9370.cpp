#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset

int n, m, t, s, g, h, a, b, d, i, j, x, T;
int dist[2001], visited[2001];
int cur, curD, nxt, nxtD;
vector<pair<int, int>> v[2001];
priority_queue<int, vector<int>, greater<int>> q;

void dijkstra(int st) {
    fill(dist, dist + n + 1, 987654321);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        curD = pq.top().first, cur = pq.top().second;
        pq.pop();
        if (curD > dist[cur]) continue;

        for (pair<int, int> next : v[cur]) {
            nxt = next.first, nxtD = next.second;
            if (dist[nxt] > dist[cur] + nxtD) {
                dist[nxt] = dist[cur] + nxtD;
                visited[nxt] = cur;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

void reset() {
    for (i = 0; i <= n; ++i) v[i].clear();
    while (!q.empty()) q.pop();
    n = m = t = s = g = h = a = b = d = i = j = x = 0;
    memset(visited, 0, 2001 * sizeof(int));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T-- != 0) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (i = 0; i < m; ++i) {
            cin >> a >> b >> d;
            v[b].push_back({a, d});
            v[a].push_back({b, d});
        }

        for (i = 0; i < t; ++i) {
            cin >> x;
            q.push(x);
        }

        memset(dist, 987654321, (n + 1) * sizeof(int));
        dist[s] = 0;

        dijkstra(s);

        b = 0;
        while (!q.empty()) {
            j = q.top();
            q.pop();

            a = 0;
            i = j;
            while(j) {
                if (!a) {
                    if (j == h) a = h;
                    else if (j == g) a = g;
                } else {
                    if (a == h && j != g) break;
                    else if (a == g && j != h) break;
                    else {
                        cout << i << " ";
                        b = 1;
                        break;
                    }
                }
                j = visited[j];
            }
        }

        if (b) cout << "\n";

        reset();
    }

    return 0;
}
// g까지의 거리 g->h의 거리 h->목적지 까지의 거리 계산해서 s부터 목적지까지의 거리와 같은지 보면됨.