/*
2023. 8. 11.
LCA
깊이에 따른 k번째 구하기
*/

#include <iostream>
using namespace std;
#include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
#include <map>
// #include <deque>
#include <cmath>

vector<int> tree[100001];
int parent[100001][17];
long long parentDist[100001][17];
int depth[100001];
int N, M, u, v, d, k, query, queryval;
map<pair<int, int>, int> m;

void dfs(int cur) {
    for (int nxt : tree[cur]) {
        if (depth[nxt] == -1) {
            depth[nxt] = depth[cur] + 1;
            parent[nxt][0] = cur;
            parentDist[nxt][0] = m[{nxt, cur}];
            dfs(nxt);
        }
    }
}

void swap() {
    int tmp = u;
    u = v;
    v = tmp;
}

void dpParent() {
    for (int i = 1; i <= k; ++i) {
        for (int j = 2; j <= N; ++j) {
            parentDist[j][i] = parentDist[j][i - 1] + parentDist[parent[j][i - 1]][i - 1];
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

long long LCA() {
    if (query == 1) {
        long long sumu = 0, sumv = 0;

        if (depth[u] < depth[v]) {
            swap();
        }

        int diff = depth[u] - depth[v];
        for (int i = 0; diff != 0; ++i) {
            if (diff % 2 == 1) {
                sumu += parentDist[u][i];
                u = parent[u][i];
            }

            diff /= 2;
        }

        if (u != v) {
            for (int i = k; i >= 0; --i) {
                if (parent[u][i] && parent[u][i] != parent[v][i]) {
                    sumu += parentDist[u][i];
                    sumv += parentDist[v][i];
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            sumu += parentDist[u][0];
            sumv += parentDist[v][0];
            u = parent[u][0];
        }

        return sumu + sumv;
    } else {
        int tu = u, tv = v;
        if (depth[tu] < depth[tv]) {
            int tmp = tu;
            tu = tv;
            tv = tmp;
        }

        int diff = depth[tu] - depth[tv];
        for (int i = 0; diff != 0; ++i) {
            if (diff % 2 == 1) {
                tu = parent[tu][i];
            }

            diff /= 2;
        }

        if (tu != tv) {
            for (int i = k; i >= 0; --i) {
                if (parent[tu][i] && parent[tu][i] != parent[tv][i]) {
                    tu = parent[tu][i];
                    tv = parent[tv][i];
                }
            }
            tu = parent[tu][0];
        }

        int ld = depth[u] - depth[tu];
        int rd = depth[v] - depth[tu];

        if (queryval <= ld + 1) {
            --queryval;
            for (int i = 0; queryval; ++i) {
                if (queryval & 1) u = parent[u][i];
                queryval >>= 1;
            }
            return u;
        } else {
            queryval = rd - (queryval - ld - 1);
            for (int i = 0; queryval; ++i) {
                if (queryval & 1) v = parent[v][i];
                queryval >>= 1;
            }
            return v;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    k = log2(N);

    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> d;

        tree[u].push_back(v);
        tree[v].push_back(u);
        m[{u, v}] = m[{v, u}] = d;
    }

    memset(depth + 1, -1, (N + 1) * sizeof(int));
    depth[1] = 0;
    dfs(1);
    dpParent();

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> query >> u >> v;

        if (query == 2) cin >> queryval;

        cout << LCA() << "\n";
    }

    return 0;
}