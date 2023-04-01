/*
Date : 2023-04-01
포장될 때마다 세계 가중치를 바꿔주면 된다.
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 100000000000
// #include <set>
// #include <stack>

vector<pair<int, int>> arr[10001];
long long dist[21][10001];
int n, m, k, from, to, w;

void dijkstra(int source) {
    for (int i = 0; i <= k; ++i) {
        fill(dist[i], dist[i] + n + 1, INF);
    }
    dist[0][source] = 0;
    priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long,pair<int, int>>>> pq;

    pq.push({dist[0][source], {source, 0}});

    while(!pq.empty()) {
        long long d = pq.top().first, cur = pq.top().second.first, world = pq.top().second.second;
        pq.pop();
        if (d > dist[world][cur]) continue;
        for (pair<int,int> i : arr[cur]) {
            int nxtD = i.first, nxt = i.second;
            if (dist[world][nxt] > dist[world][cur] + nxtD) {
                dist[world][nxt] = dist[world][cur] + nxtD;
                pq.push({dist[world][nxt], {nxt, world}});
            }

            if (world + 1 <= k && dist[world + 1][nxt] > dist[world][cur]) {
                dist[world + 1][nxt] = dist[world][cur];
                pq.push({dist[world + 1][nxt], {nxt, world + 1}});
            }
        }
    }
}

int main() {    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> w;
        arr[from].push_back({w, to});
        arr[to].push_back({w, from});
    }

    dijkstra(1);

    priority_queue<long long, vector<long long>, greater<long long>> dq;

    for (int i = 0; i <= k; ++i) {
        dq.push(dist[i][n]);
    }

    cout << dq.top();

    return 0;
}
