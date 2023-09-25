/*
2023. 8. 11.
LCA
*/

#include <iostream>
using namespace std;
#include <vector>
// #include <queue>
#include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
#include <map>
// #include <deque>
#include <cmath>
#define INF 9876543

vector<int> tree[100001];
int parent[100001][17];
int shortest[100001][17];
int longest[100001][17];
int depth[100001];
int N, M, u, v, d, k;
map<pair<int, int>, int> m;

void dfs(int cur) {
    for (int nxt : tree[cur]) {
        if (depth[nxt] == -1) {
            depth[nxt] = depth[cur] + 1;
            shortest[nxt][0] = longest[nxt][0] = m[{nxt, cur}];
            parent[nxt][0] = cur;
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
            shortest[j][i] = min(shortest[j][i - 1], shortest[parent[j][i - 1]][i - 1]);
            longest[j][i] = max(longest[j][i - 1], longest[parent[j][i - 1]][i - 1]);
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

void LCA() {
    int mx, mn;
    mx = 0, mn = INF;
    if (depth[u] < depth[v]) {
        swap();
    }

    int diff = depth[u] - depth[v];
    for (int i = 0; diff != 0; ++i) {
        if (diff % 2 == 1) {
            mn = min(mn, shortest[u][i]);
            mx = max(mx, longest[u][i]);

            u = parent[u][i];
        }

        diff /= 2;
    }

    if (u != v) {
        for (int i = k; i >= 0; --i) {
            if (parent[u][i] && parent[u][i] != parent[v][i]) {
                mn = min(mn, min(shortest[u][i], shortest[v][i]));
                mx = max(mx, max(longest[u][i], longest[v][i]));
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        mn = min(mn, min(shortest[u][0], shortest[v][0]));
        mx = max(mx, max(longest[u][0], longest[v][0]));
    }

    cout << mn << " " << mx << "\n";
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
        cin >> u >> v;

        LCA();
    }

    return 0;
}