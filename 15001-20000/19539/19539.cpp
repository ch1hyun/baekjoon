/*
2023. 7. 24.
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
// #include <cstring> // memset

int n, sum, x, cnt1, cnt2;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;

        cnt1 += x % 2;
        cnt2 += x / 2;
        sum += x;
    }

    if (sum % 3 == 0 && cnt2 - cnt1 >= 0 && (cnt2 - cnt1) % 3 == 0) cout << "YES";
    else cout << "NO";


    return 0;
}