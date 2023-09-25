#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
#include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset
// #include <map>
// #include <deque>

int arr[17][100000];
int h[100001];
int N, M, step, a, b, r;

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    h[1] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[0][i];
    }
    for (int i = 2; i <= N; ++i) {
        h[i] = h[i>>1] + 1;
    }

    step = 1;
    for (int i = 1; i <= h[N]; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j + step < N) {
                arr[i][j] = min(arr[i - 1][j], arr[i - 1][j + step]);
            }
        }
        step = step << 1;
    }

    // for (int i = 0; i <= N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // exit(0);

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        --a; --b;

        r = h[b - a + 1];
        cout << min(arr[r][a], arr[r][b + 1 - (1 << r)]) << "\n";
    }

    return 0;
}