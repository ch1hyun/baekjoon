#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
// #include <map>
// #include <deque>
#include <cmath>

int N, M, K, a, b, c;
long long d;
long long arr[4400000];
long long lazy[4400000];
long long numbers[1000001];

void f() {}

long long init(int s, int e, int idx) {
    if (s == e) return arr[idx] = numbers[s];
    int mid = (s + e) / 2;

    return arr[idx] = init(s, mid, idx * 2) + init(mid + 1, e, idx * 2 + 1);
}

void update(int s, int e, int l, int r, long long diff, int idx) {
    if (lazy[idx]) { // update lazy
        arr[idx] += lazy[idx] * (e - s + 1);
        if (s != e) {
            lazy[idx * 2] += lazy[idx]; // to children
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (r < s || e < l) return;

    if (l <= s && e <= r) {
        arr[idx] += diff * (e - s + 1);

        if (s == e) return;

        lazy[idx * 2] += diff;
        lazy[idx * 2 + 1] += diff;

        return;
    }

    int mid = (s + e) / 2;
    update(s, mid, l, r, diff, idx * 2);
    update(mid + 1, e, l, r, diff, idx * 2 + 1);

    arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
}

long long sum(int s, int e, int ql, int qr, int idx) {
    if (e < ql || qr < s) return 0;

    if (lazy[idx]) {
        arr[idx] += lazy[idx] * (e - s + 1);
        if (s != e) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (ql <= s && e <= qr) return arr[idx];

    int mid = (s + e) / 2;
    return sum(s, mid, ql, qr, idx * 2) + sum(mid + 1, e, ql, qr, idx * 2 + 1);
}

// void test() {
//     N = 1000000;
//     M = 5;
//     K = 5;

//     for (int i = 1; i <= N; ++i) {
//         numbers[i] = i;
//     }
// }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // test();

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> numbers[i];
    }

    init(1, N, 1);

    while (M || K) {
        cin >> a >> b >> c;

        if (a == 1) {
            cin >> d;

            update(1, N, b, c, d, 1);

            M--;
        } else if (a == 2) {
            cout << sum(1, N, b, c, 1) << "\n";
            K--;
        }
    }

    return 0;
}