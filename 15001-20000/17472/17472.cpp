#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
#include <map>
// #include <deque>
// #include <cmath>
#define INF 987654

int N, M, mp[10][10], visited[10][10];
map<pair<int, int>, int> m[7];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> v;

// land inform
int landCnt;
int dist[7];

// for length
int disjointSet[7];
int totalLength;

// manage direction
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int ti, tj;

// for length
int find(int vertex) {
    while(disjointSet[vertex]) {
        vertex = disjointSet[vertex];
    }

    return vertex;
}

void unionSet(int vertex1, int vertex2) {
    vertex1 = find(vertex1), vertex2 = find(vertex2);
    if (vertex1 == vertex2) return;

    if (vertex1 < vertex2) {
        disjointSet[vertex2] = vertex1;
    } else {
        disjointSet[vertex1] = vertex2;
    }
}

bool checkSet() {
    int root = find(1);
    for (int i = 2; i <= landCnt; ++i) {
        if (find(i) != root) return false;
    }

    return true;
}

void bfs(int i, int j, int length = 0, int direction = 0, int from = 0) {
    int localD;
    if (!from) {
        from = mp[i][j];
        visited[i][j] = 1;

        for (int z = 0; z < 4; ++z) {
            ti = i + dy[z], tj = j + dx[z];
            if (0 <= ti && ti < N && 0 <= tj && tj < M) {
                if (!mp[ti][tj]) {
                    if (dy[z] == 1) localD = 3;
                    else if (dy[z] == -1) localD = 1;
                    else if (dx[z] == 1) localD = 2;
                    else localD = 4;

                    bfs(ti, tj, 1, localD, from);
                } else {
                    if (!visited[ti][tj]) bfs(ti, tj);
                }
            }
        }
    } else {
        switch(direction) {
            case 1:
                ti = i - 1;
                tj = j;
                break;
            case 2:
                ti = i;
                tj = j + 1;
                break;
            case 3:
                ti = i + 1;
                tj = j;
                break;
            case 4:
                ti = i;
                tj = j - 1;
                break;
        }

        if (0 <= ti && ti < N && 0 <= tj && tj < M) {
            if (!mp[ti][tj]) {
                bfs(ti, tj, length + 1, direction, from);
            } else {
                int to = mp[ti][tj];
                if (length >= 2 && !m[from][{to, length}]) {
                    m[from][{to, length}] = m[to][{from, length}] = 1;

                    v.push({length, {to, from}});
                }
            }
        }
    }
}

void searchLand(int i, int j) {
    mp[i][j] = landCnt;
    visited[i][j] = 1;

    for (int z = 0; z < 4; ++z) {
        ti = i + dy[z], tj = j + dx[z];
        if (0 <= ti && ti < N && 0 <= tj && tj < M && mp[ti][tj] && !visited[ti][tj]) {
            searchLand(ti, tj);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mp[i][j];
        }
    }

    // attach numbers
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (mp[i][j] && !visited[i][j]) {
                ++landCnt;
                searchLand(i, j);
            }
        }
    }

    // search edges
    for (int i = 0; i < N; ++i) memset(visited[i], 0, M * sizeof(int));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (mp[i][j] && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    // get length
    disjointSet[0] = -1;
    int vertex1, vertex2, length;
    while (!v.empty()) {
        length = v.top().first, vertex1 = v.top().second.first, vertex2 = v.top().second.second;
        v.pop();
        if (find(vertex1) == find(vertex2)) continue;

        totalLength += length;
        unionSet(vertex1, vertex2);
    }

    if (checkSet()) cout << totalLength;
    else cout << -1; 

    return 0;
}