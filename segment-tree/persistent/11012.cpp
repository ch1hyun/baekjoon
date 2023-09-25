/*
2023. 8. 18.
*/

#include <iostream>
using namespace std;
#include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <map>
// #include <deque>
// #include <cmath>
#define MAX 100002

struct Node {
    int cl = 0, cr = 0, v = 0;
} Init_Node;

vector<Node> PST;
int PST_root[MAX];

void init(int l, int r, int idx) {
    if (l == r) return;
    int mid = (l + r) / 2;

    PST[idx].cl = PST.size();
    PST.push_back(Init_Node);
    PST[idx].cr = PST.size();
    PST.push_back(Init_Node);

    init(l, mid, PST[idx].cl);
    init(mid + 1, r, PST[idx].cr);
}

void update(int l, int r, int py, int diff, int index) {
    if (l == r) return;
    int mid = (l + r) / 2;
    if (py <= mid) {
        int now = PST[index].cl;
        Node tmp;
        tmp.cl = PST[now].cl;
        tmp.cr = PST[now].cr;
        tmp.v = PST[now].v + diff;
        PST[index].cl = PST.size();
        PST.push_back(tmp);
        update(l, mid, py, diff, PST[index].cl);
    } else {
        int now = PST[index].cr;
        Node tmp;
        tmp.cl = PST[now].cl;
        tmp.cr = PST[now].cr;
        tmp.v = PST[now].v + diff;
        PST[index].cr = PST.size();
        PST.push_back(tmp);
        update(mid + 1, r, py, diff, PST[index].cr);
    }
}

int sum(int l, int r, int ql, int qr, int idx) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return PST[idx].v;
    int mid = (l + r) / 2;
    return sum(l, mid, ql, qr, PST[idx].cl) + sum(mid + 1, r, ql, qr, PST[idx].cr);
}

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    
    while (T--) {
        int N, M; cin >> N >> M;

        PST.clear();
        PST.resize(2);
        memset(PST_root, 0, sizeof(PST_root));
        PST_root[0] = 1;
        init(1, MAX - 1, 1);
        vector<int> map[MAX];

        for (int i = 0; i < N; ++i) {
            int x, y; cin >> x >> y;
            map[y + 1].push_back(x + 1);
        }

        for (int i = 1; i < MAX; ++i) {
            Node tmp;
            int bf = PST_root[i - 1];
            tmp.cl = PST[bf].cl;
            tmp.cr = PST[bf].cr;
            tmp.v = PST[bf].v;
            PST_root[i] = PST.size();
            PST.push_back(tmp);

            for (int j : map[i]) {
                PST[PST_root[i]].v += 1;
                update(1, MAX - 1, j, 1, PST_root[i]);
            }
        }

        long long res = 0;
        while (M--) {
            int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
            res += sum(1, MAX - 1, (x1 + 1), (x2 + 1), PST_root[y2 + 1]);
            res -= sum(1, MAX - 1, (x1 + 1), (x2 + 1), PST_root[y1]);
        }

        cout << res << "\n";
    }

    return 0;
}