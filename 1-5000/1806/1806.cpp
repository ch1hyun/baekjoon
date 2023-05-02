/*
Date : 2023-05-02
*/

#include <iostream>
using namespace std;
// #include <vector>
#include <queue>
// #include <algorithm>
// #include <set>
// #include <stack>
using ll = long long;

int n, st, en, minLen;
ll sum, s, arr[100000];

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sum = arr[0];
    st = 0;
    en = 0;
    minLen = 100001;

    while (st != n && en != n) {
        if (sum >= s) {
            if (en - st + 1 < minLen) minLen = en - st + 1;

            sum -= arr[st];
            ++st;
            if (en < st) en = st;
        }
        else {
            ++en;
            if (en != n) sum += arr[en];
        }
    }

    if (minLen == 100001) minLen = 0;
    cout << minLen;

    return 0;
}
