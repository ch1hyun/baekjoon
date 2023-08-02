#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset

int Q, x, r;
pair<int, int> a[100000];

void addA(int n) {
    int l= 0;
    int mid;

    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid].first > n) l = mid + 1;
        else if (a[mid].first < n) r = mid - 1;
        else if (a[mid].first == n) return mid;
    }
}

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    return 0;
}