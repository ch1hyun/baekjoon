#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset

int n, used[100001], v1, v2;

void f() {}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    used[1] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> v1 >> v2;

        if (!used[v1] && used[v2]) used[v1] = v2;
        else if (used[v1] && !used[v2]) used[v2] = v1;
    }

    for (int i = 2; i <= n; ++i) {
        cout << used[i] << "\n";
    }
    
    return 0;
}