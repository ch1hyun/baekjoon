/*
2023. 8. 8.
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
#include <map>
// #include <deque>

int R, C;
int mxcnt;
char word[21];
char mp[21][21];
map<char, int> m;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int ti, tj;

void dfs(int i, int j, int cnt = 0) {
    m[mp[i][j]] = 1;
    ++cnt;

    for (int z = 0; z < 4; ++z) {
        ti = i + dy[z], tj = j + dx[z];
        if (1 <= ti && ti <= R && 1 <= tj && tj <= C && !m[mp[ti][tj]]) {
            dfs(ti, tj, cnt);
        }
    }

    m[mp[i][j]] = 0;

    if (cnt > mxcnt) mxcnt = cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 1; i <= R; ++i) {
        cin >> word;
        for (int j = 1; j <= C; ++j) {
            mp[i][j] = word[j - 1];
        }
    }

    dfs(1, 1);

    cout << mxcnt;

    return 0;
}