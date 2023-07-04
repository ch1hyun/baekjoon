/*
2023. 7. 4.

*/

#include <iostream>
#include <cstring>
using namespace std;
// #include <vector>
#include <queue>
// #include <algorithm>
// #include <set>
// #include <stack>

int n, m, i, j, temp;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

// disjoint sets
int dset[201];

void initDset() {
    memset(dset, 0, 201);
}

int find2(int idx) {
    if (dset[idx] > 0) {
        dset[idx] = find2(dset[idx]);
        return dset[idx];
    }
    else return idx;
}

void unionSet(int idx1, int idx2) {
    idx1 = find2(idx1);
    idx2 = find2(idx2);
    if (idx1 == idx2) return;

    if (dset[idx1] > dset[idx2]) {
        dset[idx1] = idx2;
    } else {
        if (dset[idx1] == dset[idx2]) {
            --dset[idx1];
        }
        dset[idx2] = idx1;
    }
}

int checkSet() {
    int tmpRt, rt = find2(1);
    for (int i = 2; i <= n; ++i) {
        tmpRt = find2(i);
        if (tmpRt != rt) return 0;
    }

    return 1;
}
// end of disjoint sets

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int totalCost = 0;
    initDset();

    cin >> n;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            cin >> temp;
            if (i >= j || i == n) continue;

            if (temp < 0) {
                totalCost += temp * -1;
                unionSet(i, j);
            } else {
                pq.push({temp, {i, j}});
            }
        }
    }


    int cost, to, from, cnt = 0;
    queue<pair<int, int>> q;
    while (!pq.empty()) {
        if (checkSet()) break;
        cost = pq.top().first, to = pq.top().second.first, from = pq.top().second.second;
        pq.pop();

        if (find2(to) == find2(from)) continue;

        q.push({to, from});
        ++cnt;
        totalCost += cost;
        unionSet(to, from);
    }

    cout << totalCost << " " << cnt << "\n";
    while (!q.empty()) {
        cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }

    return 0;
}
