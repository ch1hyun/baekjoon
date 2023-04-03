/*
Date : 2023-04-03
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <set>
// #include <stack>

long long n, k, u = 1, d = 1;
int c[1001][1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    c[1][0] = 1, c[1][1] = 1;
    for (int i = 1; i < n; ++i) {
        c[i + 1][0] = 1, c[i + 1][i + 1] = 1;
        for (int j = 0; j < n; ++j) {
            c[i + 1][j + 1] = ((c[i][j] % 10007) + (c[i][j + 1] % 10007)) % 10007;
        }
    }

    cout << c[n][k];
    return 0;
}
