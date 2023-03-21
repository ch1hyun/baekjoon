/*
Date : 2023-03-21
*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <queue>

bool chk[1001];
vector<int> arr[1001];
int n, m, to, from, v;

void dfs(int idx) {
    chk[idx] = true;
    cout << idx << " ";
    
    for(int& nxt: arr[idx]) {
        if(chk[nxt]) continue;
        dfs(nxt);
    }
}

void bfs(int s) {
    queue<int> q;
    chk[s] = true;
    q.push(s);

    while (!q.empty()) {
        int z = q.front();
        cout << z << " ";
        q.pop();

        for(int &nxt: arr[z]) {
            if (chk[nxt]) continue;
            chk[nxt] = true;
            q.push(nxt);
        }
    }
}

int main() {
    cin >> n >> m >> v;

    for(int i = 0; i < m; ++i) {
        cin >> to >> from;
        arr[to].push_back(from);
        arr[from].push_back(to);
    }

    for(int i = 1; i <= n; ++i) {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(v);
    cout << "\n";
    for(int i = 1; i <= n; ++i) chk[i] = false;
    bfs(v);

    return 0;
}
