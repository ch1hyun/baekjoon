/*
Date : 2023-05-04
*/

#include <iostream>
using namespace std;
using ll = long long;
// #include <vector>
// #include <queue>
#include <algorithm>
// #include <set>
// #include <stack>
// #include <string>
#define MAX 1000000001
#define MIN -1000000001

int n, st, md, en, minSt, minMd, minEn;
ll arr[5001], sum, minSum;

void f() {
    st = 1;
    minSum = MAX * (ll)3;

    while (st != n - 1) {
        md = st + 1;
        en = n;

        while (md < en) {
            sum = arr[st] + arr[md] + arr[en];

            if (abs(minSum) >= abs(sum)) {
                minSum = sum;
                minSt = st;
                minMd = md;
                minEn = en;
            }

            if (sum < 0) ++md;
            else --en;
        }

        ++st;
    }

    cout << arr[minSt] << " " << arr[minMd] << " " << arr[minEn];
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    f();

    return 0;
}
