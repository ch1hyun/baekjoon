/*
Date : 2023-03-27
dijkstra algorithm
*/

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

vector<pair<int,int>> arr1[1001];
vector<pair<int,int>> arr2[1001];
int dist1[1001];
int dist2[1001];
bool vis[1001];
int n, m, x, from, to, w;

void dijkstra1(int source) {
    fill(dist1, dist1 + n + 1, 987654321);
    dist1[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({dist1[source], source});

    while(!pq.empty()) {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (d > dist1[cur]) continue;
        for (pair<int,int> i : arr1[cur]) {
            int nxtD = i.first, nxt = i.second;
            if (dist1[nxt] > dist1[cur] + nxtD) {
                dist1[nxt] = dist1[cur] + nxtD;
                pq.push({dist1[nxt], nxt});
            }
        }
    }
}

void dijkstra2(int source) {
    fill(dist2, dist2 + n + 1, 987654321);
    dist2[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({dist2[source], source});

    while(!pq.empty()) {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (d > dist2[cur]) continue;
        for (pair<int,int> i : arr2[cur]) {
            int nxtD = i.first, nxt = i.second;
            if (dist2[nxt] > dist2[cur] + nxtD) {
                dist2[nxt] = dist2[cur] + nxtD;
                pq.push({dist2[nxt], nxt});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> w;
        arr1[from].push_back({w, to});
        arr2[to].push_back({w, from});
    }

    dijkstra1(x);
    dijkstra2(x);

    priority_queue<int> tmp;
    for (int i = 1; i <= n; ++i) {
        tmp.push(dist1[i] + dist2[i]);
    }

    cout << tmp.top();

    return 0;
}
