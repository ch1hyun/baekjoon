/*
2023. 8. 19.
*/

#include <iostream>
using namespace std;
// #include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
// #include <map>
// #include <deque>
#include <cmath>

int n;
float res;
pair<float, float> pos[101];
priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> pq;

// disjoint set
int ds[101];

int find(int s) {
    if (s == ds[s]) return s;
    else return ds[s] = find(ds[s]);
}

void update(int v1, int v2) {
    v1 = find(v1), v2 = find(v2);

    if (v1 < v2) {
        ds[v2] = v1;
    } else {
        ds[v1] = v2;
    }
}


void f() {}

float getDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        ds[i] = i;
        cin >> pos[i].first >> pos[i].second;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            pq.push({getDistance(pos[i].first, pos[i].second, pos[j].first, pos[j].second), {i, j}});
        }
    }

    int tmp1, tmp2;
    float d;
    while (!pq.empty()) {
        tmp1 = pq.top().second.first, tmp2 = pq.top().second.second;
        d = pq.top().first;
        pq.pop();

        if (find(tmp1) == find(tmp2)) continue;

        res += d;
        update(tmp1, tmp2);
    }

    cout << fixed;
    cout.precision(2);
    cout << res;

    return 0;
}