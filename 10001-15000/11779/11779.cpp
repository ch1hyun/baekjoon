/*
Date : 2023-04-01
다익스트라 역추적
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 999987654321
// #include <set>
// #include <stack>

vector<pair<int, int>> arr[1001];
int n, e, from, to, w, s, t;
long long dist[1001];
int path[1001];
bool endFlag = false, updateFlag = false;

void dijkstra(int source) {
    fill(dist, dist + 1001, INF);
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
                path[nxt] = cur;
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
        updateFlag = false;
        cin >> from >> to >> w;
        for (int j = 0; j < arr[from].size(); ++j) {
            if (arr[from][j].second == to && arr[from][j].first > w) {
                arr[from][j].first = w;
                updateFlag = true;
            }
        }
        if(!updateFlag) arr[from].push_back({w, to});
    }
    cin >> s >> t;

    dijkstra(s);
    path[s] = 0;
    cout << dist[t] << "\n";

    stack<int> stk;
    int tmp = t;
    while(tmp != 0) {
        stk.push(tmp);
        tmp = path[tmp];
    }

    cout << stk.size() << "\n";

    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
