/*
Date : 2023-03-26
문제를 잘 읽자...
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int k, v, e, from, to, colors[20001];
vector<int> point[20001];
bool endFlag;

void pointInit() {
    for (int i = 1; i <= v; ++i) {
        point[i].clear();
        colors[i] = -1;
    }
}

void f(int s, int c) {
    queue<int> q;
    int tmp;
    q.push(s);
    colors[s] = c;

    while (!q.empty()) {
        if (endFlag) break;
        tmp = q.front();
        q.pop();

        for (int&nxt : point[tmp]) {
            if (colors[tmp] == colors[nxt]) {endFlag = true; break;}
            if (colors[nxt] == -1) {
                colors[nxt] = (colors[tmp] + 1) % 2;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> k;

    while ((k--) != 0) {
        /* Initial */
        cin >> v >> e;
        pointInit();
        endFlag = false;

        for (int z = 0; z < e; ++z) {
            cin >> from >> to;
            point[from].push_back(to);
            point[to].push_back(from);
        }

        for (int z = 1; z <= v; ++z) {
            if (colors[z] == -1) f(z, 1);
            if (endFlag) break;
        }

        if (endFlag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
