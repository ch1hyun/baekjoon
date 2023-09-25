/*
2023. 8. 31.
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
// #include <cstring> // memset
// #include <map>
// #include <deque>
// #include <cmath>

int N, M, K, P, a, b, c;
int w1[10001]; // 정점 가중치
pii minV; // 가중치 중 가장 작은 노드;

int visited[10001]; // Prim's Algorithm
vector<pii> v[10001]; // 간선 연결 정보

priority_queue<tiii, vector<tiii>, greater<tiii>> pq; // Prim's Algorithm
// <가중치, 이전 정점, 현재 정점>

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> P;

    minV = {-1, 1001};
    for (int i = 1; i <= N; ++i) {
        cin >> w1[i]; // 가중치

        if (minV.second > w1[i]) minV = {i, w1[i]};
    }
    for (int i = 0; i < P; ++i) { // 간선 연결 정보 추가
        cin >> a >> b >> c;
        v[a].push_back({c * 2 + w1[a] + w1[b], b});
        v[b].push_back({c * 2 + w1[a] + w1[b], a});
    }

    ll sum = minV.second;
    pq.push({0, 0, minV.first});
    while (!pq.empty()) {
        tiii tmp = pq.top();
        pq.pop();

        int l = get<0>(tmp), f = get<1>(tmp), s = get<2>(tmp);

        if (visited[s]) continue;
        visited[s] = 1;
        sum += l;

        for (pii i : v[s]) {
            if (!visited[i.second]) pq.push({i.first, s, i.second});
        }
    }

    cout << sum;

    return 0;
}