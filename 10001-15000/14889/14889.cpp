#include <iostream>
using namespace std;
#include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset

int n, mn, idx, soul[21][21], used[21];

void f(int cnt = 1) {
    if (idx == n / 2) {
        int st = 0, lt = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (used[i] && used[j]) st += soul[i][j] + soul[j][i];
                else if (!used[i] && !used[j]) lt += soul[i][j] + soul[j][i];
            }
        }

        if (mn > abs(lt - st)) mn = abs(lt - st);
    } else {
        for (int i = cnt; i <= n; ++i) {
            if (used[i]) continue;

            used[i] = 1;
            ++idx;
            f(i + 1);
            --idx;
            used[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> soul[i][j];
    }

    mn = 10000001;
    f();

    cout << mn;

    return 0;
}