/*
2023. 8. 7.
k 번째 최단경로
*/

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
#define INF 9876543

int n, m, k, a, b, c, tmp;
vector<pair<int, int>> v[1001];
priority_queue<int> pqout[1001];

// sync
bool onetoone;
int onetoonecost;
int diff;

void dijkstra(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, st});
    int cur, curd, nxt, nxtd;
    while (!pq.empty()) {
        curd = pq.top().first, cur = pq.top().second;
        pq.pop();

        for (pair<int, int> i : v[cur]) {
            nxt = i.first, nxtd = curd + i.second;
            if (pqout[nxt].size() < k) {
                pqout[nxt].push(nxtd);
                pq.push({nxtd, nxt});
            } else {
                if (pqout[nxt].top() > nxtd) {
                    pqout[nxt].pop();
                    pqout[nxt].push(nxtd);
                    pq.push({nxtd, nxt});
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;

        v[a].push_back({b, c});
    }

    pqout[1].push(0);
    dijkstra(1);

    for (int i = 1; i <= n; ++i) {
        if (k > pqout[i].size()) cout << -1 << "\n";
        else {
            cout << pqout[i].top() << "\n";
        }
    }

    return 0;
}