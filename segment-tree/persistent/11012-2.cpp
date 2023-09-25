/*
2023. 9. 4.
*/

#include <iostream>
#include <tuple>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
#include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <map>
// #include <deque>
// #include <cmath>
#define MAX (100000 + 4)

int T, N, M, K, a, b, c, x, y, l, r, t;
vector<int> xidx[MAX];

struct Node {
    int val = 0;
    int r = 0;
    int l = 0;
} Initial_Node;

vector<Node> PST;
int PST_Head[MAX];

/* Initial PST - all node has 0 value */
void init(int s, int e, int idx) {
    if (s == e) return;

    int mid = (s + e) / 2;

    PST[idx].l = PST.size();
    PST.push_back(Initial_Node);
    init(s, mid, PST[idx].l);

    PST[idx].r = PST.size();
    PST.push_back(Initial_Node);
    init(mid + 1, e, PST[idx].r);
}

/* Update Graph - Additinal Values are appended to PST backward */
void update(int s, int e, int x, int idx) {
    if (s == e) return;

    int mid = (s + e) / 2;
    if (x <= mid) {
        Node tmp = PST[PST[idx].l];
        ++tmp.val;

        PST[idx].l = PST.size();
        PST.push_back(tmp);
        update(s, mid, x, PST[idx].l);
    } else {
        Node tmp = PST[PST[idx].r];
        ++tmp.val;

        PST[idx].r = PST.size();
        PST.push_back(tmp);
        update(mid + 1, e, x, PST[idx].r);
    }
}

int sum(int s, int e, int l, int r, int idx) {
    if (r < s || e < l) return 0;

    if (l <= s && e <= r) return PST[idx].val;
    
    int mid = (s + e) / 2;

    return sum(s, mid, l, r, PST[idx].l) + sum(mid + 1, e, l, r, PST[idx].r);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--) {
        PST.resize(2);
        PST[1] = Initial_Node; 
        memset(PST_Head, 0, sizeof(PST_Head));
        PST_Head[0] = 1;

        init(1, MAX - 1, 1);

        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            xidx[++y].push_back(++x);
        }

        for (int i = 1; i <= MAX - 1; ++i) {
            PST_Head[i] = PST.size();
            PST.push_back({PST[PST_Head[i - 1]].val, PST[PST_Head[i - 1]].r, PST[PST_Head[i - 1]].l});

            for(int x : xidx[i]) {
                ++PST[PST_Head[i]].val; // Update는 자식을 업데이트하기 때문에 루트는 직접 증가시켜줘야 함.
                update(1, MAX - 1, x, PST_Head[i]);
            }

            // reset
            xidx[i].clear();
        }

        ll ans = 0;
        while (M--) {
            cin >> l >> r >> b >> t;
            ++l; ++r; ++t;

            ans += sum(1, MAX - 1, l, r, PST_Head[t]) - sum(1, MAX - 1, l, r, PST_Head[b]);
        }

        cout << ans << "\n";
    }

    return 0;
}