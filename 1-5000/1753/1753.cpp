/*
Date : 2023-03-27
*/

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

vector<pair<int,int>> arr[20001];
int dist[20001];
bool vis[20001];

int v, e, k, from, to, w;

void dijkstra(int s) {
    fill(dist, dist + v + 1, 5000000);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // type container less <- greater로 비교연산 바꿈
    pq.push({dist[s], s});

    while(!pq.empty()) {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();
        if (d > dist[cur]) continue;

        for (pair<int, int> i : arr[cur]) {
            int nxtD = i.first, nxt = i.second;
            if (dist[nxt] > dist[cur] + nxtD) {
                dist[nxt] = dist[cur] + nxtD;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> v >> e >> k;
    for (int i = 0; i < e; ++i) {
        cin >> from >> to >> w;
        arr[from].push_back({w, to});
    }

    dijkstra(k);

    for (int i = 1; i <= v; ++i) {
        if (dist[i] == 5000000) cout << "INF\n";
        else cout << dist[i] << "\n";
    }


    return 0;
}
