#include <iostream>
#include <tuple>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <fstream>
// #include <map>
// #include <deque>
// #include <cmath>

// 2024. 2. 4.

#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define MAX 1000000000

ll segment[4000001];
int A[1000001];
int N, M, i, j, k;
int op;

ll init(int s, int e, int idx) {
    if (s == e) return segment[idx] = 0;

    int mid = (s + e) / 2;

    return segment[idx] = init(s, mid, idx * 2) + init(mid + 1, e, idx * 2 + 1);
}

void update(int s, int e, int x, int diff, int idx) {
    if (s <= x && x <= e) {
        segment[idx] += diff;
        if (s == e) return;

        int mid = (s + e) / 2;

        update(s, mid, x, diff, idx * 2);
        update(mid + 1, e, x, diff, idx * 2 + 1);
    }
}

ll sum(int s, int e, int l, int r, int idx) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return segment[idx];

    int mid = (s + e) / 2;

    return sum(s, mid, l, r, idx * 2) + sum(mid + 1, e, l, r, idx * 2 + 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    memset(A, 0, sizeof(A));

    cin >> N >> M;

    init(1, N, 1);

    for (int z = 0; z < M; ++z) {
        cin >> op;

        if (op) { // modify
            cin >> i >> k;

            int diff = k - A[i];
            A[i] = k;

            update(1, N, i, diff, 1);
        } else { // sum
            cin >> i >> j;
            if (i > j) {
                int tmp = i;
                i = j;
                j = tmp;
            }

            cout << sum(1, N, i, j, 1) << "\n";
        }
    }

    return 0;
}