/*
Date : 2023-04-01
반례를 잡는게 중요한 것 같다.
v1, v2가 각각 1, n일 때,
v1이 v2보다 멀리있는 경우,
v2가 v1보다 멀리있는 경우
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
// #include <set>
// #include <stack>

vector<pair<int, int>> arr[801];
int n, e, from, to, w, v1, v2, sum = 0;
int dist[801];
bool endFlag = false;

void dijkstra(int source) {
    fill(dist, dist + 801, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    pq.push({dist[source], source});

    while(!pq.empty()) {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();
        if (d > dist[cur]) continue;
        for (pair<int,int> i : arr[cur]) {
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

    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        cin >> from >> to >> w;
        arr[from].push_back({w, to});
        arr[to].push_back({w, from});
    }
    cin >> v1 >> v2;

    int oneToV1, oneToV2, v1ToV2, v2ToV1, v1ToN, v2ToN;

    dijkstra(1);
    oneToV1 = dist[v1], oneToV2 = dist[v2];
    if (oneToV1 == INF || oneToV2 == INF) endFlag = true;

    dijkstra(v1);
    v1ToV2 = dist[v2], v1ToN = dist[n];
    if (v1ToV2 == INF || v1ToN == INF) endFlag = true;

    dijkstra(v2);
    v2ToV1 = dist[v1], v2ToN = dist[n];
    if (v2ToV1 == INF || v2ToN == INF) endFlag = true;

    
    if (endFlag) cout << -1;
    else {cout << min(
        oneToV1 + v1ToV2 + v2ToN,
        oneToV2 + v2ToV1 + v1ToN
    );}

    return 0;
}
