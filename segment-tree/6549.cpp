/*
2023. 8. 20.
*/

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
// #include <cmath>

int n;
long long mx;
long long h[100001];
int tree[400000];

void init(int s, int e, int idx) {
    if (s == e) {
        tree[idx] = s;
    } else {
        int mid = (s + e) / 2;
        init(s, mid, idx * 2);
        init(mid + 1, e, idx * 2 + 1);

        if (h[tree[idx * 2]] <= h[tree[idx * 2 + 1]]) {
            tree[idx] = tree[idx * 2];
        } else {
            tree[idx] = tree[idx * 2 + 1];
        }
    }
}

int findMin(int s, int e, int ql, int qr, int idx) {
    if (qr < s || e < ql) return -1;
    if (ql <= s && e <= qr) return tree[idx];

    int mid = (s + e) / 2;
    int m1 = findMin(s, mid, ql, qr, idx * 2);
    int m2 = findMin(mid + 1, e, ql, qr, idx * 2 + 1);

    if (m1 == -1) return m2;
    else if (m2 == -1) return m1;
    else {
        if (h[m1] <= h[m2]) return m1;
        else return m2;
    }
}

void getMaxArea(int s, int e) {
    int pivot = findMin(0, n - 1, s, e, 1);

    if (mx < h[pivot] * (e - s + 1)) mx = h[pivot] * (e - s + 1);

    if (s <= pivot - 1) getMaxArea(s, pivot - 1);
    if (pivot + 1 <= e) getMaxArea(pivot + 1, e);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> n;
        if (!n) break;

        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        init(0, n - 1, 1);

        mx = -1;

        getMaxArea(0, n - 1);

        cout << mx << "\n";
    }

    return 0;
}