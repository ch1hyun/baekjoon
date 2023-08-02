#include <stdio.h>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
#define rep(i, n) for(i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)

vector<int> g[200001];
vector<int> gv[200001];
int gIdx;
long long sumG[200001], w3[200001];

int N, to, from, color, w1[200001], w2[200001];

vector<pair<int, vector<int>>> v[200001];
priority_queue<int> pq;

void dfs(int st, int color = -1, int before = -1, int beforeGIdx = -1) {
    int localGIdx, size = v[st].size();

    for (int i = 0; i < size; ++i) {
        if (color == -1 || v[st][i].first != color) {
            localGIdx = gIdx++;
            sumG[localGIdx] += w1[st];
            gv[st].push_back(localGIdx);
        } else localGIdx = beforeGIdx;

        for (int j : v[st][i].second) {
            if (before != j) {
                gv[j].push_back(localGIdx);
                sumG[localGIdx] += w1[j];
                dfs(j, v[st][i].first, st, localGIdx);
            }
        }
    }
}

int getColorIndex(int s, int c) {
    int mid, left = 0, right = v[s].size() - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (v[s][mid].first > c) right = mid - 1;
        else if (v[s][mid].first < c) left = mid + 1;
        else return mid;
    }

    return left;
}

void f() {}

int main() {

    scanf("%d", &N);

    int tmpIdx;
    int i;
    rep(i, N - 1) {
        scanf("%d %d %d", &to, &from, &color);

        tmpIdx = getColorIndex(to, color);
        if (tmpIdx >= v[to].size()) {
            v[to].push_back({color, {from}});
        } else if (v[to][tmpIdx].first != color) {
            v[to].insert(v[to].begin() + tmpIdx, {color, {from}});
        }
        else v[to][tmpIdx].second.push_back(from);

        tmpIdx = getColorIndex(from, color);
        if (tmpIdx >= v[from].size()) {
            v[from].push_back({color, {to}});
        } else if (v[from][tmpIdx].first != color) {
            v[from].insert(v[from].begin() + tmpIdx, {color, {to}});
        }
        else v[from][tmpIdx].second.push_back(to);
    }

    REP(i, 1, N) {
        scanf("%d", &w1[i]);
    }
    dfs(1);
    int temp;
    REP(i, 1, N) {
        scanf("%d", &temp);
        pq.push(temp);
        for (int j : gv[i]) {
            w3[i] += sumG[j];
        }
    }
    sort(w3 + 1, w3 + N + 1);

    long long sumM = 0, sumN = 0;

    REP(i, 1, N) {
        sumM += pq.top() * w3[N-i+1];
        sumN += pq.top() * w3[i];
        pq.pop();
    }

    printf("%lld\n%lld", sumN, sumM);
     
    return 0;
}