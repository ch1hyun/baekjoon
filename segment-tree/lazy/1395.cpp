/*
2023. 9. 3.
*/

#include <iostream>
#include <tuple>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <map>
// #include <deque>
// #include <cmath>
#define MAX (100000 + 10)

int N, M, K, a, b, c;

/* Lazy Segment Tree */
int seg[MAX * 4];
int lazy[MAX * 4];

void lazyUpdate(int s, int e, int idx) {
    if (!lazy[idx]) return;

    seg[idx] = e - s + 1 - seg[idx];

    if (s != e) {
        lazy[idx * 2] = !lazy[idx * 2];
        lazy[idx * 2 + 1] = !lazy[idx * 2 + 1];
    }

    lazy[idx] = 0;
}

void update(int s, int e, int l, int r, int idx) {
    lazyUpdate(s, e, idx);
    if (r < s || e < l) return;

    if (l <= s && e <= r) {
        seg[idx] = e - s + 1 - seg[idx];
        if (s != e) {
            lazy[idx * 2] = !lazy[idx * 2];
            lazy[idx * 2 + 1] = !lazy[idx * 2 + 1];
        }
        return;
    }

    int mid = (s + e) / 2;

    update(s, mid, l, r, idx * 2);
    update(mid + 1, e, l, r, idx * 2 + 1);

    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int sum(int s, int e, int l, int r, int idx) {
    lazyUpdate(s, e, idx);
    if (r < s || e < l) return 0;

    if (l <= s && e <= r) {
        return seg[idx];
    }

    int mid = (s + e) / 2;

    return sum(s, mid, l, r, idx * 2) + sum(mid + 1, e, l, r, idx * 2 + 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;

        if (!a) {
            update(1, N, b, c, 1);
        } else {
            cout << sum(1, N, b, c, 1) << "\n";
        }
    }

    return 0;
}