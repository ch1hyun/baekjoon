/*
2023. 9. 3.
*/

#include <iostream>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#include <vector>
#include <queue>
#include <algorithm> // sort, min, max
// #include <set>
#include <stack>
// #include <cstring> // memset
#include <map>
// #include <deque>
// #include <cmath>

int N, M, S, T, K, a, b, c;
vector<int> v[10001];

/* SCC */
stack<int> s;
int finished[10001];
int vId[10001];
int id;

vector<vector<int>> scc;
int sccNum;

/* SCC GROUP */
vector<int> newV[10001];
int indegree[10001];
int fromS[10001];
int dist[10001];

int dfs(int cur) {
    vId[cur] = ++id;

    s.push(cur);

    int result = vId[cur];

    for (int nxt : v[cur]) {
        if (!vId[nxt]) result = min(result, dfs(nxt));
        else if (!finished[nxt]) result = min(result, vId[nxt]);
    }

    if (result == vId[cur]) {
        vector<int> tmp;
        ++sccNum;

        while (true) {
            int t = s.top();
            s.pop();

            tmp.push_back(t);
            finished[t] = sccNum;

            if (t == cur) break;
        }

        scc.push_back(tmp);
    }

    return result;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    scc.push_back({});

    cin >> N >> M >> S >> T;

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    /* SSC 그룹 생성 */
    for (int i = 1; i <= N; ++i) {
        if (!vId[i]) dfs(i);
    }

    /* 생성된 SSC 그룹 노드화 + 간선 연결 */
    map<pii, int> m;

    for (int i = 1; i <= sccNum; ++i) {
        for (int j : scc[i]) {
            for (int z : v[j]) {
                if (i != finished[z] && !m[{i, finished[z]}]) {
                    newV[i].push_back(finished[z]);
                    ++indegree[finished[z]];
                    m[{i, finished[z]}] = 1;
                }
            }
        }
    }

    /* 위상 정렬 수행, S가 속한 그룹에서 출발한 것만 갱신 */
    queue<int> q;
    for (int i = 1; i <= sccNum; ++i) {
        if (!indegree[i]) q.push(i);
    }

    fromS[finished[S]] = 1;
    dist[finished[S]] = scc[finished[S]].size();

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int nxt : newV[t]) {
            if (fromS[t]) {
                dist[nxt] = max(dist[nxt], (int)(dist[t] + scc[nxt].size()));
                fromS[nxt] = 1;
            }

            if (!(--indegree[nxt])) {
                q.push(nxt);
            }
        }
    }

    cout << dist[finished[T]];

    return 0;
}