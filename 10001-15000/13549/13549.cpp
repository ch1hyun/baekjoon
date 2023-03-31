/*
Date : 2023-04-01
*/

#include <iostream>
using namespace std;
// #include <vector>
#include <queue>
#include <algorithm>
// #include <set>
// #include <stack>

int n, k;
int dist[100001];

void dijkstra(int source) {
    fill(dist, dist + 100001, 987654321);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    pq.push({dist[source], source});

    while(!pq.empty()) {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();
        if (d > dist[cur]) continue;
        if (cur < 100000 && dist[cur + 1] > d + 1) {
            dist[cur + 1] = d + 1;
            pq.push({dist[cur + 1], cur + 1});
        }
        if (cur > 0 && dist[cur - 1] > d + 1) {
            dist[cur - 1] = d + 1;
            pq.push({dist[cur - 1], cur - 1});
        }
        if (0 < cur && cur < 50001 && dist[cur * 2] > d) {
            dist[cur * 2] = d;
            pq.push({dist[cur * 2], cur * 2});
        }
    }
}

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);

    cin >> n >> k;
    dijkstra(n);

    cout << dist[k];

    return 0;
}
