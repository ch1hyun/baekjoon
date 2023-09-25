/*
2023. 8. 7.
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
#include <map>

vector<int> g[200001];
vector<int> gv[200001];
int gIdx;
long long sumG[200001], w3[200001];

int N, to, from, color, w1[200001], w2[200001];

vector<pair<int, vector<int>>> v[200001];
priority_queue<int> pq;
map<int, int> m[200001];

void dfs(int st, int color = -1, int before = -1, int beforeGIdx = -1) {
    int localGIdx;

    for (int i = 0; i < v[st].size(); ++i) {
        if (color == -1 || v[st][i].first != color) {
            localGIdx = gIdx++;
            g[localGIdx].push_back(st);
            sumG[localGIdx] += w1[st];
            gv[st].push_back(localGIdx);
        } else localGIdx = beforeGIdx;

        for (int j : v[st][i].second) {
            if (before != j) {
                g[localGIdx].push_back(j);
                gv[j].push_back(localGIdx);
                sumG[localGIdx] += w1[j];
                dfs(j, v[st][i].first, st, localGIdx);
            }
        }
    }
}

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    int tmpIdx;
    for (int i = 0; i < N - 1; ++i) {
        cin >> to >> from >> color;

        if (!m[to][color]) {
            v[to].push_back({color, {}});
            m[to][color] = v[to].size();
            v[to][m[to][color] - 1].second.push_back(from);
        } else {
            v[to][m[to][color] - 1].second.push_back(from);
        }

        if (!m[from][color]) {
            v[from].push_back({color, {}});
            m[from][color] = v[from].size();
            v[from][m[from][color] - 1].second.push_back(to);
        } else {
            v[from][m[from][color] - 1].second.push_back(to);
        }
    }

    for (int i = 1; i <= N; ++i) cin >> w1[i];
    dfs(1);
    int temp;
    for (int i = 1; i <= N; ++i) {
        cin >> temp;
        pq.push(temp);
        for (int j : gv[i]) {
            w3[i] += sumG[j];
        }
    }
    sort(w3 + 1, w3 + N + 1);

    long long sumM = 0, sumN = 0;

    for (int i = 1; i <= N; ++i) {
        sumM += pq.top() * w3[N-i+1];
        sumN += pq.top() * w3[i];
        pq.pop();
    }

    cout << sumN << "\n";
    cout << sumM;
     
    return 0;
}